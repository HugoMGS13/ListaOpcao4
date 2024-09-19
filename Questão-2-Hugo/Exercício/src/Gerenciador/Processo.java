package Gerenciador;

//Discentes: Hugo Martins Gaspar da Silva e Polyana dos Santos Moraes
//Matrículas: 202311140020 e 202311140012

public class Processo {
    /**
     * Nessa classe, eu criei o tipo Processo, que será a classe que originará os objetos que serão armazenados na fila
     * Cada processo tem os campoes: id, name, priority e wait.
     */
    private String id;
    private String name;
    private int priority;
    private double wait;

    public Processo(String id, String name, int priority, double wait){
        this.id = id;
        this.name = name;
        this.priority = priority;
        this.wait = wait;
    }

    public Processo(){}

    // Getters and Setters
    
    public String getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public int getPriority() {
        return priority;
    }
    public double getWait() {
        return wait;
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setPriority(int priority) {
        this.priority = priority;
    }
    public void setWait(double wait) {
        this.wait = wait;
    }
    
}
