#include "params_helper.h"

void print_action(action *act)
{
    if (act->properties_amount == 0)
    {
        printf("\nL'action n'a aucune propriété\n");
    }

    for (int i = 0; i < act->properties_amount; i++)
    {
        printf("\nPropriete %d : %s -> %s", i, act->properties[i]->name, act->properties[i]->value);
    }

    if (act->option_amount == 0)
    {
        printf("\nL'action n'a aucune option\n");
    }

    for (int i = 0; i < act->option_amount; i++)
    {
        printf("\nOption %d : %s -> %s", i, act->options[i]->name, act->options[i]->value);
    }
}

void print_full_params(param_container *params)
{
    if (params->action_amount == 0)
    {
        printf("\nPas d'action présente.");
    }

    for (int i = 0; i < params->action_amount; i++)
    {
        printf("\n\nAction %d", i);
        print_action(params->actions[i]);
    }

    if (params->task_amount == 0)
    {
        printf("\nPas de task présente.\n");
    }

    for (int i = 0; i < params->task_amount; i++)
    {
        printf("\nTask %d :", i);
        print_task(params->tasks[i]);
    }
}

void add_action_to_params(param_container *params, action *act)
{
    int size = params->action_amount;
    action **new_action_list = malloc(sizeof(action *) * (size + 1));
    for (int i = 0; i < size; i++)
    {
        new_action_list[i] = params->actions[i];
    }

    new_action_list[size] = act;

    if (params->actions != NULL)
    {
        free(params->actions);
    }

    params->actions = new_action_list;
    params->action_amount++;
}

void add_task_to_params(param_container *params, task *ta)
{
    print_task(ta);
    int size = params->task_amount;
    task **new_task_list = malloc(sizeof(task *) * (size + 1));
    for (int i = 0; i < size; i++)
    {
        new_task_list[i] = params->tasks[i];
    }

    new_task_list[size] = ta;

    if (params->tasks != NULL)
    {
        free(params->tasks);
    }

    params->tasks = new_task_list;
    params->task_amount++;
}

void print_task(task *ta)
{
    if(ta->properties_amount == 0){
        printf("\nLa tache ne possede pas de propriete\n");
    }

    for(int i = 0; i < ta->properties_amount; i++){
        printf("\nPropriete %d : %s -> %s", i, ta->properties[i]->name, ta->properties[i]->value);
    }

    if(ta->action_amount == 0){
        printf("\nLa tache ne contient pas d'action\n");
    }

    for(int i = 0; i < ta->action_amount; i++){
        printf("Action %d : %s", i, ta->actions_name[i]);
    }
}