#!/usr/bin/ruby

require 'socket'

if ARGV.length < 2
    puts "you must enter the host ip and the game port"
    exit 1
end
socket = TCPSocket.new(ARGV[0], ARGV[1])
if !socket
    puts "connection error"
    exit 1
end
puts "connected"
begin
    while line = socket.gets
        puts line
        if line == "your turn\n"
            ind = $stdin.gets.chomp
            socket.puts ind
        end
    end
rescue
    puts "an error has occured"
    socket.close
    exit 1
end
socket.close
