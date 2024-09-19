package Gerenciador;

//Discentes: Hugo Martins Gaspar da Silva e Polyana dos Santos Moraes
//Matrículas: 202311140020 e 202311140012

public class GerenciadorDeTarefas extends Processo {
    private Processo[] Processos; // Cria o vetor, que armazenará a fila, do tipo Object chamado: "Processos"
    private int tamanho; // Variável que corresponde ao tamanho da fila

    public GerenciadorDeTarefas(int tamanho_inicial){
        this.Processos = new Processo[tamanho_inicial]; // Inicializa o vetor com um tamanho inicial
        this.tamanho = 0;
    }

    public boolean cheia(){
        /**
         * Verifica se a fila dinâmica "Processos" está cheia
         */
        if (this.tamanho == Processos.length){
            return true;
        } else{
            return false;
        }
    }

    public boolean vazia(){
        /**
         * Verifica se a fila dinâmica "Processos" está vazia
         */
        if(tamanho == 0){
            return true;
        } else {
            return false;
        }
    }

    public void enfileirar(Processo processo){
        /**
         * Esse método tem como função enfileirar um elemento na fila dinâmica Processos
         * Se a fila estiver cheia, o método irá aumentar o tamanho da fila, criando outra fila com um tamanho maior e fazendo com que a fila original receba o tamanho da nova fila. Logo depois disso, o novo elemento será adicionado no final da fila
         * Se a fila não estiver cheia, o elemento será adicionado no final da fila
         */
        if (this.cheia() == true){
            Processo[] fila_nova = new Processo[this.Processos.length + 1];
            for (int i = 0; i < this.Processos.length ; i++){
                fila_nova[i] = this.Processos[i];
            }
            this.Processos = fila_nova;
            this.Processos[tamanho] = processo;
            this.tamanho = this.tamanho + 1;
        }
        else{
            this.Processos[tamanho] = processo;
            this.tamanho++;
        }
    }

    public Processo executar_processo() {
        /** 
         * Esse método é responsável por executar o processo que entrou primeiro, seguindo o algoritmo FIFO.
        */
        if (vazia()) {
            System.out.println("Não há processos para executar");
            return null;
        } else {
            Processo processoExecutado = this.Processos[0]; // Armazena o primeiro elemento
            for (int i = 0; i < tamanho - 1; i++) {
                this.Processos[i] = this.Processos[i + 1];
            }
            this.Processos[tamanho - 1] = null; // Limpa a última posição
            this.tamanho--;
            return processoExecutado; // Retorna o elemento que foi removido
        }
    }
    

    public void Imprimir(){
        /**
         * Método feito para imprimir os elementos da fila e seus campos5
         */
        for (int i = 0; i < Processos.length ; i++){
            if (Processos[i] == null){
                System.out.println("Processo " + (i+1) + " = " + "null");
            }else{
                Processo processo = (Processo) Processos[i];
                System.out.println("Processo " + (i+1) + " = " + processo.getName() + ", Id: " + processo.getId() + ", priority: "+ processo.getPriority() + ", wait: " + processo.getWait()); // Pesquisar uma forma de acessar os campos do Objeto "Processo"
            }
        }
    }

    public int getTamanho() {
        return tamanho;
    }

    public Processo[] getProcessos() {
        return Processos;
    }

}
