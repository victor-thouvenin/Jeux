import java.util.Arrays;
import java.util.Map;
import static java.util.Map.entry;
import java.util.Random;
import javax.swing.*;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;

@SuppressWarnings("serial")
public class Demineur extends JPanel {
    static byte[][] grid;
    static int size = 0;
    static int bnb = 0;
    static int pos;
    static int fnb = 0;
    static boolean k = true;
    static String lang = "fr";
    static String[] langs = {"fr", "en"};
    static Map <String, Map <String, String>> msg = Map.ofEntries(
        entry("name", Map.ofEntries(
            entry("en", "Minesweeper"),
            entry("fr", "Démineur")
        )),
        entry("restart", Map.ofEntries(
            entry("en", "restart\n"),
            entry("fr", "c'est reparti\n")
        )),
        entry("win", Map.ofEntries(
            entry("en", "you won! WOU-HOU\n"),
            entry("fr", "gagné ! YOUPI !\n")
        )),
        entry("lost", Map.ofEntries(
            entry("en", "BOOM! you lost\n"),
            entry("fr", "BOUM ! perdu\n")
        )),
        entry("remaining_flags", Map.ofEntries(
            entry("en", "flags remaining: "),
            entry("fr", "drapeaux restants : ")
        )),
        entry("no_flag", Map.ofEntries(
            entry("en", "no flag left\n"),
            entry("fr", "il n'y a plus de drapeau\n")
        )),
        entry("end_msg", Map.ofEntries(
            entry("fr", "il n'y a plus de drapeau, appuyer sur '%s' pour révéler toute la grille\nAVERTISSEMENT : si une mine n'a pas été marquée la partie sera perdu\n"),
            entry("en", "no flag left, press '%s' to reveal the whole grid\nWARNING: if a mine has not been flaged you will lose the game\n")
        )),
        entry("error_parameter", Map.ofEntries(
            entry("en", "Error: a positive integer is expected: "),
            entry("fr", "Erreur : un nombre entier positif est attendu : ")
        )),
        entry("error_lang", Map.ofEntries(
            entry("en", "Error: this language is not available: "),
            entry("fr", "Erreur : cette langue n'est disponible : ")
        ))
    );
    static JFrame f;
    static JTextArea t;

    public static void init_grid() {
        for (int i = 0; i < size*size; i++)
            grid[i/size][i%size] = 4;
        fnb = 0;
        pos = 0;
        mine_grid();
        grid[0][0] |= 1;
        print_grid(true);
    }

    public static void mine_grid() {
        Random r = new Random();
        int pos;
        int x;
        int y;
        for (int i = 0; i < bnb; i++) {
            pos = r.nextInt(size*size);
            x = pos%size;
            y = pos/size;
            if ((grid[y][x]&8) == 8) {
                --i;
                continue;
            }
            grid[y][x] |= 8;
            if (y > 0) {
                grid[y-1][x] += 16;
                if (x < size-1)
                    grid[y-1][x + 1] += 16;
            }
            if (x < size-1) {
                grid[y][x + 1] += 16;
                if (y < size-1)
                    grid[y + 1][x + 1] += 16;
            }
            if (y < size-1) {
                grid[y + 1][x] += 16;
                if (x > 0)
                    grid[y + 1][x-1] += 16;
            }
            if (x > 0) {
                grid[y][x-1] += 16;
                if (y > 0)
                    grid[y-1][x-1] += 16;
            }
        }
    }

    public static void print_grid(boolean k) {
        String text;
        String border = "#";

        border = border.repeat(size*2+3);
        text = border + "\n";

        for (byte[] row : grid) {
            text += "# ";
            for (byte n : row) {
                if (k && (n&1) == 1)
                    text += "x ";
                else if ((n&2) == 2)
                    text += "F ";
                else if ((n&4) == 4)
                    text += "@ ";
                else if ((n&~1) == 0)
                    text += "  ";
                else
                    text += (n >> 4) + " ";
            }
            text += "#\n";
        }
        text += border + "\n";
        t.append(text);
    }

    public static boolean check_grid() {
        for (byte[] row : grid) {
            for (byte n : row) {
                if ((n&14)%14 != 0)
                    return false;
            }
        }
        return true;
    }

    public static void move(int dir) {
        int x = pos%size;
        int y = pos/size;
        switch (dir) {
            case 1:
                if (y > 0) {
                    grid[y-1][x] |= 1;
                    grid[y][x] &= ~1;
                    pos -= size;
                }
                break;
            case 2:
                if (x < size-1) {
                    grid[y][x+1] |= 1;
                    grid[y][x] &= ~1;
                    pos++;
                }
                break;
            case 3:
                if (y < size-1) {
                    grid[y+1][x] |= 1;
                    grid[y][x] &= ~1;
                    pos += size;
                }
                break;
            case 4:
                if (x > 0) {
                    grid[y][x-1] |= 1;
                    grid[y][x] &= ~1;
                    pos--;
                }
                break;
        }
    }

    public static boolean flag_pos() {
        int x = pos%size;
        int y = pos/size;
        boolean flg = (grid[y][x]&2) == 0;
        k = !flg || fnb == bnb;
        if (flg && fnb == bnb) {
            t.setText(msg.get("no_flag").get(lang));
            return false;
        }
        fnb += flg ? 1 : -1;
        grid[y][x] ^= 2;
        return true;
    }

    public static void reveal() {
        String text = "";
        String border = "#";

        pos = -1;
        border = border.repeat(size*2+3);
        text += border + "\n";
        for (byte[] row : grid) {
            text += "# ";
            for (byte n : row) {
                if ((n&9) == 9)
                    text += "X ";
                else if ((n&10) == 10)
                    text += "F ";
                else if ((n&10) == 2)
                    text += "/ ";
                else if ((n&10) == 8)
                    text += "B ";
                else if ((n&~5) == 0)
                    text += "  ";
                else
                    text += (n >> 4) + " ";
            }
            text += "#\n";
        }
        text += border + "\n";
        t.append(text);
    }

    public static boolean check_lost(int x, int y) {
        if ((grid[y][x]&12) == 0)
            return false;
        if ((grid[y][x]&8) == 8) {
            t.setText(msg.get("lost").get(lang));
            grid[y][x] &= ~4;
            reveal();
            return true;
        }
        grid[y][x] &= ~6;
        if ((grid[y][x]>>4) != 0)
            return false;
        if (y > 0) {
            check_lost(x, y-1);
            if (x < size-1)
                check_lost(x+1, y-1);
        }
        if (x < size-1) {
            check_lost(x+1, y);
            if (y < size-1)
                check_lost(x+1, y+1);
        }
        if (y < size-1) {
            check_lost(x, y+1);
            if (x > 0)
                check_lost(x-1, y+1);
        }
        if (x > 0) {
            check_lost(x-1, y);
            if (y > 0)
                check_lost(x-1, y-1);
        }
        return false;
    }

    public static boolean check_all() {
        boolean ok = true;
        byte n;
        for (int i = 0; i < size*size; i++) {
            n = grid[i/size][i%size];
            if ((n&10) == 8) {
                grid[i/size][i%size] &= ~4;
                grid[i/size][i%size] |= 1;
                ok = false;
            } else if ((n&6) == 4)
                grid[i/size][i%size] &= ~4;
        }
        if (!ok) {
            t.setText(msg.get("lost").get(lang));
            reveal();
        }
        return check_grid();
    }

    public static void start() {
        grid = new byte [size][size];
        f = new JFrame(msg.get("name").get(lang));
        t = new JTextArea();
        init_grid();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(600, 600);
        f.getContentPane().setBackground(new Color(45, 55, 65));
        f.setVisible(true);
        Demineur kb = new Demineur();
        t.setFont(new Font("Monospaced", Font.PLAIN, 14));
        t.setOpaque(false);
        t.setForeground(new Color(210, 210, 210));
        f.add(kb);
        f.add(t);
    }

    public static void main(String[] args) {
        if (args.length > 0 && !args[0].equals("-")) {
            try {
                size = Integer.parseInt(args[0]);
            } catch (Exception e) {}
            if (size < 1) {
                System.out.println(msg.get("error_parameter").get(lang) + args[0]);
                System.exit(1);
            }
        } else
            size = 10;
        
        if (args.length > 1 && !args[1].equals("-")) {
            try {
                bnb = Integer.parseInt(args[1]);
            } catch (Exception e) {}
            if (bnb < 1) {
                System.out.println(msg.get("error_parameter").get(lang) + args[1]);
                System.exit(1);
            }
        } else if (size < 10)
            bnb = size;
        else if (size < 20)
            bnb = size * 2;
        else
            bnb = size * 4;

        if (args.length > 2) {
            if (!Arrays.asList(langs).contains(args[2])) {
                System.out.println(msg.get("error_lang").get(lang) + args[2]);
                for (String l : langs) {
                    System.out.print(l + ", ");
                }
                System.out.println("\b\b\n");
                System.exit(1);
            }
            lang = args[2];
        }
        start();
    }

    public Demineur() {
        KeyListener kl = new MyKeyListener();
        addKeyListener(kl);
        setFocusable(true);
    }

    public class MyKeyListener implements KeyListener {
        @Override
        public void keyTyped(KeyEvent e) {
        }

        @Override
        public void keyPressed(KeyEvent e) {
            int code = e.getKeyCode();
            boolean flg = true;
            if (code == KeyEvent.VK_R) {
                t.setText(msg.get("restart").get(lang));
                init_grid();
                return;
            }
            if (code == KeyEvent.VK_Q)
                System.exit(0);
            if (pos == -1)
                return;
            t.setText("");
            k = true;
            switch (code) {
                case KeyEvent.VK_UP:
                    move(1);
                    break;
                case KeyEvent.VK_RIGHT:
                    move(2);
                    break;
                case KeyEvent.VK_DOWN:
                    move(3);
                    break;
                case KeyEvent.VK_LEFT:
                    move(4);
                    break;
                case KeyEvent.VK_F:
                    if ((grid[pos/size][pos%size]&4) == 4)
                        flg = flag_pos();
                    break;
                case KeyEvent.VK_G:
                    if (fnb == bnb) {
                        if (check_all()) {
                            pos = -1;
                            t.setText(msg.get("win").get(lang));
                            print_grid(false);
                        }
                        return;
                    }
                    break;
                case KeyEvent.VK_ENTER:
                    int x = pos%size;
                    int y = pos/size;
                    boolean b = (grid[y][x]&4) == 4;
                    if (b && check_lost(x, y))
                        return;
                    k = !b || (grid[y][x]&~1) == 0;
                    break;
            }
            if (fnb == bnb && check_grid()) {
                pos = -1;
                t.setText(msg.get("win").get(lang));
                print_grid(false);
                return;
            }
            if (flg)
                t.append(msg.get("remaining_flags").get(lang) + (bnb - fnb) + "\n");
            print_grid(k);
            if (fnb == bnb) {
                t.append(String.format(msg.get("end_msg").get(lang), "G"));
            }
        }

        @Override
        public void keyReleased(KeyEvent e) {
            return;
        }
    }
}
