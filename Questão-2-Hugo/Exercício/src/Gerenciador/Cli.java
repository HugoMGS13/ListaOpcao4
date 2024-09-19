package Gerenciador;

//Discentes: Hugo Martins Gaspar da Silva e Polyana dos Santos Moraes
//Matrículas: 202311140020 e 202311140012

import java.util.Scanner; //Biblioteca para entrada de dados em Java (O java não tem um padrão igual o C++)

public class Cli {
    /**
     * Essa classe é responsável pela criação da interface vista pelo usuário
     */
    Scanner scan = new Scanner(System.in);

    public void interagir(){

        GerenciadorDeTarefas gerenciador = new GerenciadorDeTarefas(1);

        while (true){
            System.out.println("Qual operação você deseja realizar? \n1 - Enfileirar novos elementos\n2 - Executar processos com maior tempo de espera\n3 - Imprimir a fila\n4 - Encerrar programa");

            int escolha  = scan.nextInt();

            if (escolha == 1){
                System.out.println("Digite o nome do processo:");
                String nome = scan.next();
                System.out.println("Digite o ID do processo");
                String id = scan.next();
                System.out.println("Digite a prioridade do processo");
                int prio = scan.nextInt();
                System.out.println("Insira o wait do processo");
                double wait = scan.nextDouble();

                Processo processo = new Processo(id, nome , prio, wait);
                    
                gerenciador.enfileirar(processo);

            }
            else if (escolha == 2){
                gerenciador.executar_processo();
            }
            else if (escolha == 3){
                gerenciador.Imprimir();
            }
            else if (escolha == 4){
                break;
            }
        }
    }
    
}
