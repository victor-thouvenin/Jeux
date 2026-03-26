require 'socket'

@online = false
if ARGV[0] == "--LAN"
    if ARGV.length < 2
        puts "il faut saisir le port du jeu pour jouer en ligne."
        exit 1
    end
    begin
        socket = TCPServer.new (ARGV[1])
    rescue
        puts "Une erreur s'est produite"
    end
    puts "en attente de connexion"
    @client = socket.accept
    @online = true
end

@tab = []
@player = 0
7.times{|i| @tab[i] = []; @tab[i][5] = nil}

def print_tab
    grid = ""
    7.times{|i| grid << " #{i+1}"}; grid << "\n"
    6.times.reverse_each{|i|
        7.times{|j|
            grid << "|#{@tab[j][i] == nil ? ' ' : @tab[j][i]}"
        }
        grid << "|\n"
    }
    grid << "---------------\n\n"
    print grid
    if @online
        @client.print grid
    end
end

def play()
    if @player == 0 || !@online
        if !@online
            print "tour du joueur #{@player+1} : "
        else
            puts "à ton tour"
            @client.print "tour de l'adversaire\n\n"
        end
        ind = $stdin.gets.chomp.to_i() -1
        if ind < 0 || ind > 6
            puts "entrée invalide"
            return false
        end
    else
        begin
            @client.puts "à ton tour"
        rescue
            raise "error"
        end
        print "tour de l'adversaire\n\n"
        ind = @client.gets.chomp.to_i() -1
        if ind < 0 || ind > 6
            @client.puts "entrée invalide"
            return false
        end
    end
    @tab[ind].each_with_index {|v,i|
        if v == nil
            @tab[ind][i] = @player == 0 ? 'O' : '@'
            return true
        elsif i == 5
            if @player == 0  || !@online
                print "Cette colonne est déjà pleine\n\n"
            else
                @client.print "Cette colonne est déjà pleine\n\n"
            end
            return false
        end
    }
    return true
end

def check_win
    @tab.each_with_index{|t,i|
        t.each_with_index{|v, j|
            line = i < 4 && v == @tab[i+1][j] && v == @tab[i+2][j] && v == @tab[i+3][j]
            column = j < 3 && v == t[j+1] && v == t[j+2] && v == t[j+3]
            diagonal = i < 4 && j < 3 && v == @tab[i+1][j+1] && v == @tab[i+2][j+2] && v == @tab[i+3][j+3]
            diagonal2 = i < 4 && j > 2 && v == @tab[i+1][j-1] && v == @tab[i+2][j-2] && v == @tab[i+3][j-3]
            if v != nil && (line || column || diagonal || diagonal2)
                return true
            end
        }
    }
    return false
end

def check_tie
    @tab.each_with_index{|t,i|
        t.each_with_index{|v,j|
            if v == nil
                return false
            end
        }
    }
    return true
end

print_tab
loop do
    begin
        if !play
            next
        end
    rescue
        puts "Une erreur s'est produite"
        break
    end
    print_tab
    if check_win
        if !@online
            puts "le joueur #{@player+1} a gagné"
        elsif @player == 0
            puts "gagné ! SUUUUPER"; @client.puts "perdu. (c'est le jeu ma pauvre lucette)"
        else
            puts "perdu. (c'est le jeu ma pauvre lucette)"; @client.puts "gagné ! SUUUUPER"
        end
        break
    elsif check_tie
        puts "match nul"
        if @online
            @client.puts "match nul"
        end
        break
    end
    @player ^= 1
end

if @online
    @client.close
end
