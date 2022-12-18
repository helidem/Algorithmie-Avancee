import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        System.out.println("Quicksort & Priority Queue");
        // nous allons utiliser la méthode Quicksort de Java et ensuite la classe Priority_Queue pour comparer les performances d’extraction de min ou de max.
        // Nous allons utiliser plusieurs tableaux de nombres aléatoires de taille 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000.
        // enregistrer la taille du tableau et le temps dans un fichier csv.
        // taille;temps
        // temps en millisecondes

        File file1 = new File("dataQS.csv");
        File file2 = new File("dataPQ.csv");
        try {
            file1.createNewFile();
            file2.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Quicksort
        // 1000
        try {
            BufferedWriter writer1 = new BufferedWriter(new FileWriter(file1, true));
            BufferedWriter writer2 = new BufferedWriter(new FileWriter(file2, true));
            int[] tab1000 = new int[1000];
            for (int i = 0; i < tab1000.length; i++) {
                tab1000[i] = (int) (Math.random() * 1000);
            }
            long start = System.currentTimeMillis();
            Arrays.sort(tab1000);
            long end = System.currentTimeMillis();
            long time = end - start;
            System.out.println("Quicksort 1000: " + time + " ms");
            // enregistrer dans le fichier
            String line = "1000," + time + "\n";
            writer1.write(line);
            // 10000
            int[] tab10000 = new int[10000];
            for (int i = 0; i < tab10000.length; i++) {
                tab10000[i] = (int) (Math.random() * 10000);
            }
            start = System.currentTimeMillis();
            Arrays.sort(tab10000);
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Quicksort 10000: " + time + " ms");
            String line2 = "10000," + time + "\n";
            writer1.write(line2);
            // 100000
            int[] tab100000 = new int[100000];
            for (int i = 0; i < tab100000.length; i++) {
                tab100000[i] = (int) (Math.random() * 100000);
            }
            start = System.currentTimeMillis();
            Arrays.sort(tab100000);
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Quicksort 100000: " + time + " ms");
            String line3 = "100000," + time + "\n";
            writer1.write(line3);
            // 1000000
            int[] tab1000000 = new int[1000000];
            for (int i = 0; i < tab1000000.length; i++) {
                tab1000000[i] = (int) (Math.random() * 1000000);
            }
            start = System.currentTimeMillis();
            Arrays.sort(tab1000000);
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Quicksort 1000000: " + time + "ms");
            String line4 = "1000000," + time + "\n";
            writer1.write(line4);
            // 10000000
            int[] tab10000000 = new int[10000000];
            for (int i = 0; i < tab10000000.length; i++) {
                tab10000000[i] = (int) (Math.random() * 10000000);
            }
            start = System.currentTimeMillis();
            Arrays.sort(tab10000000);
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Quicksort 10000000: " + time + "ms");
            String line5 = "10000000," + time + "\n";
            writer1.write(line5);
            // 100000000
            int[] tab100000000 = new int[100000000];
            for (int i = 0; i < tab100000000.length; i++) {
                tab100000000[i] = (int) (Math.random() * 100000000);
            }
            start = System.currentTimeMillis();
            Arrays.sort(tab100000000);
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Quicksort 100000000: " + time + "ms");
            String line6 = "100000000," + time + "\n";
            writer1.write(line6);
            writer1.close();
            // Priority Queue
            // 1000
            PriorityQueue<Integer> pq1000 = new PriorityQueue<Integer>();
            for (int i = 0; i < tab1000.length; i++) {
                pq1000.add(tab1000[i]);
            }
            start = System.currentTimeMillis();
            while (!pq1000.isEmpty()) {
                pq1000.poll();
            }
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Priority Queue 1000: " + time + "ms");
            String line7 = "1000," + time + "\n";
            writer2.write(line7);
            // 10000
            PriorityQueue<Integer> pq10000 = new PriorityQueue<Integer>();
            for (int i = 0; i < tab10000.length; i++) {
                pq10000.add(tab10000[i]);
            }
            start = System.currentTimeMillis();
            while (!pq10000.isEmpty()) {
                pq10000.poll();
            }
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Priority Queue 10000: " + time + "ms");
            String line8 = "10000," + time + "\n";
            writer2.write(line8);
            // 100000
            PriorityQueue<Integer> pq100000 = new PriorityQueue<Integer>();
            for (int i = 0; i < tab100000.length; i++) {
                pq100000.add(tab100000[i]);
            }
            start = System.currentTimeMillis();
            while (!pq100000.isEmpty()) {
                pq100000.poll();
            }
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Priority Queue 100000: " + time + "ms");
            String line9 = "100000," + time + "\n";
            writer2.write(line9);
            // 1000000
            PriorityQueue<Integer> pq1000000 = new PriorityQueue<Integer>();
            for (int i = 0; i < tab1000000.length; i++) {
                pq1000000.add(tab1000000[i]);
            }
            start = System.currentTimeMillis();
            while (!pq1000000.isEmpty()) {
                pq1000000.poll();
            }
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Priority Queue 1000000: " + time + "ms");
            String line10 = "1000000," + time + "\n";
            writer2.write(line10);
            // 10000000
            PriorityQueue<Integer> pq10000000 = new PriorityQueue<Integer>();
            for (int i = 0; i < tab10000000.length; i++) {
                pq10000000.add(tab10000000[i]);
            }
            start = System.currentTimeMillis();
            while (!pq10000000.isEmpty()) {
                pq10000000.poll();
            }
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Priority Queue 10000000: " + time + "ms");
            String line11 = "10000000," + time + "\n";
            writer2.write(line11);
            // 100000000
            PriorityQueue<Integer> pq100000000 = new PriorityQueue<Integer>();
            for (int i = 0; i < tab100000000.length; i++) {
                pq100000000.add(tab100000000[i]);
            }
            start = System.currentTimeMillis();
            while (!pq100000000.isEmpty()) {
                pq100000000.poll();
            }
            end = System.currentTimeMillis();
            time = end - start;
            System.out.println("Priority Queue 100000000: " + time + "ms");
            String line12 = "100000000," + time + "\n";
            writer2.write(line12);
            writer2.close();

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}