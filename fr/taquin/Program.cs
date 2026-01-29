using System;

class Program {
    static int size;
    static int[][] grid = {};

    static void gridCreator() {
        grid = new int[size][];
        for (int i = 0; i <= size-1; i++){
            grid[i] = new int[size];
        }
        for (int i = 0; i <= size*size-1; i++){
            grid[i/size][i%size] = i;
        }
    }

    static void scramble(ref int fs) {
        Random rnd = new Random(DateTime.Now.Millisecond);
        rnd = new Random(rnd.Next());
        int[] dir = {-size, -1, 1, size};
        for (int i = 0; i < 50*size; i++){
            int r = rnd.Next(4);
            move(dir[r], ref fs);
            rnd = new Random(rnd.Next());
        }
    }

    static bool checkGrid() {
        for (int i = 0; i < size*size-1; i++){
            if (grid[i/size][i%size] != i){
                return false;
            }
        }
        return true;
    }

    static void printGrid() {
        string border = string.Concat(Enumerable.Repeat("#", grid.Length*3+3));
        Console.WriteLine("\n"+border);
        foreach (int[] t in grid){
            Console.Write("# ");
            foreach (int i in t) {
                if (i == size*size-1) {
                    Console.Write(string.Concat(Enumerable.Repeat(" ", 3)));
                } else {
                    Console.Write("{0:X}{1:X} ", i/size, i%size);
                }
            }
            Console.WriteLine("#");
        }
        Console.WriteLine(border);
    }

    static void move(int dir, ref int fs) {
        int nfs = fs+dir;
        if (nfs < 0 || nfs > size*size-1 || (nfs/size != fs/size && nfs%size != fs%size))
            return;
        int tmp = grid[nfs/size][nfs%size];
        grid[nfs/size][nfs%size] = grid[fs/size][fs%size];
        grid[fs/size][fs%size] = tmp;
        fs = nfs;
    }

    static int Main(string[] arg) {
        if (arg.Length < 2)
            size = 4;
        else if (!Int32.TryParse(arg[1], out size)) {
            Console.WriteLine("Erreur: la taille doit être un nombre");
            return 1;
        } else if (size < 3) {
            Console.WriteLine("Erreur: la grille est trop peite");
            return 1;
        } else if (size > 16) {
            Console.WriteLine("Erreur: la grille est trop grande");
            return 1;
        }
        Console.WriteLine("taille : {0}X{0}", size);
        gridCreator();
        string val;
        int count = 0;
        int fs = size*size-1;
        printGrid();
        scramble(ref fs);
        printGrid();
        do {
            ConsoleKeyInfo k = Console.ReadKey();
            val = k.Key.ToString();
            switch(val) {
                case "UpArrow":
                    move(-size, ref fs);
                    break;
                case "LeftArrow":
                    move(-1, ref fs);
                    break;
                case "RightArrow":
                    move(1, ref fs);
                    break;
                case "DownArrow":
                    move(size, ref fs);
                    break;
                default:
                    Console.Write(val == "q" ? "\b \b\n" : "\b \b");
                    continue;
            }
            count++;
            printGrid();
            if (checkGrid()){
                Console.WriteLine("victoire en {0} {1}", count, count > 1 ? "coups" : "coup");
                break;
            }
            Console.WriteLine("coup : {0}", count);
        } while (val != "Q");
        return 0;
    }
}