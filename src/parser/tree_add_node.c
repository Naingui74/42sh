/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** tree_sm.c
*/

#include "lexer.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
parser_t *tree_new_sm(parser_t *tree)
{
    tree->sm = realloc(tree->sm, sizeof(semicolons_t *) * (tree->size_sm + 1));
    if (tree->sm == NULL)
        return NULL;
    tree->sm[tree->size_sm] = malloc(sizeof(semicolons_t));
    tree->sm[tree->size_sm]->size_and = 0;
    tree->sm[tree->size_sm]->and_tab = malloc(sizeof(and_t *));
    tree->sm[tree->size_sm]->and_tab[0] = malloc(sizeof(and_t));
    tree->sm[tree->size_sm]->and_tab[0]->size_or = 0;
    tree->sm[tree->size_sm]->and_tab[0]->or_tab = malloc(sizeof(or_t *));
    tree->sm[tree->size_sm]->and_tab[0]->or_tab[0] = malloc(sizeof(or_t));
    tree->sm[tree->size_sm]->and_tab[0]->or_tab[0]->size_pipe = 0;
    tree->sm[tree->size_sm]->and_tab[0]->or_tab[0]
    ->pipe = malloc(sizeof(pipe_t *));
    tree->sm[tree->size_sm]->and_tab[0]->or_tab[0]
    ->pipe[0] = malloc(sizeof(pipe_t));
    return tree;
}

static
and_t **tree_new_and(and_t **tree, int size_and)
{
    tree = realloc(tree, sizeof(and_t *) * (size_and + 1));
    if (tree == NULL)
        return NULL;
    tree[size_and] = malloc(sizeof(and_t));
    tree[size_and]->size_or = 0;
    tree[size_and]->or_tab = malloc(sizeof(or_t *));
    tree[size_and]->or_tab[0] = malloc(sizeof(or_t));
    tree[size_and]->or_tab[0]->size_pipe = 0;
    tree[size_and]->or_tab[0]->pipe = malloc(sizeof(pipe_t *));
    tree[size_and]->or_tab[0]->pipe[0] = malloc(sizeof(pipe_t));
    return tree;
}

static
or_t **tree_new_or(or_t **tree, int so)
{
    tree = realloc(tree, sizeof(or_t *) * (so + 1));
    if (tree == NULL)
        return NULL;
    tree[so] = malloc(sizeof(or_t));
    tree[so]->size_pipe = 0;
    tree[so]->pipe = malloc(sizeof(pipe_t *));
    tree[so]->pipe[0] = malloc(sizeof(pipe_t));
    return tree;
}

static
pipe_t **tree_new_pipe(pipe_t **pipe, int sp)
{
    pipe = realloc(pipe, sizeof(pipe_t *) * (sp + 1));
    if (pipe == NULL)
        return NULL;
    pipe[sp] = malloc(sizeof(pipe_t));
    return pipe;
}

parser_t *check_semicolons(parser_t *tree, char *tmp)
{
    if (tree == NULL || tmp == NULL)
        return NULL;
    tree->size_sm++;
    tree = tree_new_sm(tree);
    tree->sm[tree->size_sm]->and_tab[0]->or_tab[0]->pipe[0]->cmd = strdup(tmp);
    return tree;
}

parser_t *check_and(parser_t *tree, char *tmp)
{
    int sa = 0;

    if (tree == NULL || tmp == NULL)
        return NULL;
    tree->sm[tree->size_sm]->size_and++;
    sa = tree->sm[tree->size_sm]->size_and;
    tree->sm[tree->size_sm]->and_tab =
            tree_new_and(tree->sm[0]->and_tab, sa);
    tree->sm[tree->size_sm]->and_tab[sa]->or_tab[0]->pipe[0]->cmd
    = strdup(tmp);
    return tree;
}

parser_t *check_or(parser_t *tree, char *tmp)
{
    int ss = 0;
    int sa = 0;
    int so = 0;

    if (tree == NULL || tmp == NULL)
        return NULL;
    ss = tree->size_sm;
    sa = tree->sm[ss]->size_and;
    tree->sm[ss]->and_tab[sa]->size_or++;
    so = tree->sm[ss]->and_tab[sa]->size_or;
    tree->sm[ss]->and_tab[sa]->or_tab =
            tree_new_or(tree->sm[ss]->and_tab[sa]->or_tab, so);
    if (tree->sm[ss]->and_tab[sa]->or_tab == NULL)
        return NULL;
    tree->sm[tree->size_sm]->and_tab[sa]->or_tab[so]
            ->pipe[0]->cmd = strdup(tmp);
    return tree;
}

parser_t *check_pipe(parser_t *tree, char *tmp)
{
    int ss = 0;
    int sa = 0;
    int so = 0;
    int sp = 0;

    if (tree == NULL || tmp == NULL)
        return NULL;
    ss = tree->size_sm;
    sa = tree->sm[ss]->size_and;
    so = tree->sm[ss]->and_tab[sa]->size_or;
    tree->sm[ss]->and_tab[sa]->or_tab[so]->size_pipe++;
    sp = tree->sm[ss]->and_tab[sa]->or_tab[so]->size_pipe;
    tree->sm[ss]->and_tab[sa]->or_tab[so]->pipe =
            tree_new_pipe(tree->sm[ss]->and_tab[sa]->or_tab[so]->pipe, sp);
    tree->sm[ss]->and_tab[sa]->or_tab[so]->pipe[sp]->cmd = strdup(tmp);
    return tree;
}
