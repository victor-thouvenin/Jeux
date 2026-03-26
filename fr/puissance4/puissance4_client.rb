require 'socket'

if ARGV.length < 2
    puts "il faut saisir l'adresse IP de l'hôte et le port du jeu"
    exit 1
end
socket = TCPSocket.new(ARGV[0], ARGV[1])
if !socket
    puts "erreur de connexion"
    exit 1
end
puts "connecté"
begin
    while line = socket.gets
        puts line
        if line == "à ton tour\n"
            ind = $stdin.gets.chomp
            socket.puts ind
        end
    end
rescue
    puts "Une erreur s'est produite"
    socket.close
    exit 1
end
socket.close
