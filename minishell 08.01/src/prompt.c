/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:30:43 by antonfer          #+#    #+#             */
/*   Updated: 2024/11/27 08:33:33 by antonfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cleanup(void)
{
    // Libera o histórico de comandos
    clear_history();

    // Outras limpezas podem ser adicionadas aqui se necessário
}

void minishell_loop(void)
{
    char *line;

    line = NULL;
    printf("\e[1;1H\e[2J"); // Limpar o terminal
    // Define a função de completamento de comandos
    rl_attempted_completion_function = command_completion;
    while (1)
    {
        rl_on_new_line();
        line = readline("minishell> ");
        if (!line)
            break;
        if (*line) // Adiciona ao histórico se não for uma linha vazia
            add_history(line);
        if (strcmp(line, "exit") == 0)
        {
            free(line); // Libera a memória de 'line' antes de sair
            break;
        }
        parse_and_execute(line); // Executa o comando
        free(line); // Libera a memória de 'line' após cada comando
    }
    printf("Exiting Minishell...\n");
    cleanup(); // Chama a função de limpeza antes de sair
}