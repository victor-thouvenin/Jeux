let check_around map i j =
    let lcond = j > 0 and
        rcond = j < (List.length (List.nth map 0)) -1 and
        ucond = i > 0 and
        dcond = i < (List.length map) -1 in
        let lst = List.nth map i and
            nlst = if dcond then List.nth map (i+1) else [] and
            plst = if ucond then List.nth map (i-1) else [] in
            let l = if (lcond && (List.nth lst (j-1))) then 1 else 0 and
                r = if (rcond && (List.nth lst (j+1))) then 1 else 0 and
                u = if (ucond && (List.nth plst j)) then 1 else 0 and
                d = if (dcond && (List.nth nlst j)) then 1 else 0 and
                ul = if (ucond && lcond && (List.nth plst (j-1))) then 1 else 0 and
                ur = if (ucond && rcond && (List.nth plst (j+1))) then 1 else 0 and
                dl = if (dcond && lcond && (List.nth nlst (j-1))) then 1 else 0 and
                dr = if (dcond && rcond && (List.nth nlst (j+1))) then 1 else 0 in
                l + r + u + d + ul + ur + dl + dr

let rec line_step map i j =
    let lst = List.nth map i in
        let size = List.length lst in
            if j == size then []
            else let num = check_around map i j in
                    let st = (num == 3) || ((num == 2) && (List.nth lst j)) in st:: line_step map i (j+1)

let rec step map i =
    let size = List.length map in
        if i == size then []
        else let col = line_step map i 0 in col:: step map (i+1)

let rec print = function
    | [] -> print_string "\n"
    | l::t -> match l with
                | [] -> print_string "\n"; print t
                | b::lst -> let c = if b then "@" else " " in
                                print_string c; print (lst::t)

let rec game_of_life = function
    | [] -> Printf.printf "erreur: grille vide\n"; exit 1
    | map -> try let r = read_line () in
                if (compare r "q") == 0 then ()
                else let nmap = step map 0 in
                        print nmap; game_of_life nmap
            with End_of_file -> ()

let rec mapToBool = function
    | [] -> []
    | lst::t -> match lst with
                | [] -> [] :: mapToBool t
                | c::l -> let b = c != ' ' in
                            match (mapToBool (l::t)) with
                            | l::t -> (b::l)::t
                            | [] -> [b]::[]

let rec check_size = function
    | [] -> false
    | [l] -> true
    | l1::l2::t -> let s1 = List.length l1 and s2 = List.length l2 in if s1 != s2 then false else check_size (l2::t)

let rec strmToTab strm =
    try let s = input_line strm
        in (List.init (String.length s) (String.get s))::strmToTab strm
    with End_of_file -> []

let arg = if (Array.length Sys.argv) < 2 then (Printf.printf "erreur : fichier grille manquant\n"; exit 1) else Sys.argv.(1);;
let strm = try open_in arg with e -> Printf.printf "erreur : ce fichier est introuvable\n"; exit 1
let tab = strmToTab strm;;
close_in strm;;
if check_size tab then () else (Printf.printf "erreur : mauvais format\n"; exit 1)
let map = mapToBool tab;;
print map;;
game_of_life map;;
