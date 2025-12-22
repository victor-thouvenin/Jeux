function love.load()
    love.window.setMode(1920, 1080)
    function addElem()
        table.insert(serie, love.math.random(9))
    end
    function setSerie()
        serie = {};
        addElem()
        ind = 0
        show_state = 1
        nb_s = 1
        loose = false
        timer = nb_s
        key_num = 0
    end
    function printSerie(num, color)
        local size = 76
        local x_off = ((num-1)%3)
        local y_off = ((num-1)/3 - ((num-1)%3)/3)
        local pos_x = 750 + x_off*(size-0.75)
        local pos_y = 500 - y_off*size
        love.graphics.setColor(color)
        love.graphics.rectangle("fill", pos_x + x_off, pos_y + y_off, size, size)
        love.graphics.setColor(1, 1, 1)
        love.graphics.print(num, pos_x + x_off + 33, pos_y + y_off + 28)
    end
    serie = {};
    ind = 0
    show_state = 0
    okgo = false
    nb_s = 1
    sped = 1
    loose = false
    timer = 0
    key_num = 0
end

function love.keypressed(key)
    if key == 'q' or key == "echap" then
        love.event.quit()
    elseif show_state == 0 then
        addElem()
        show_state = 1
        timer = nb_s
    elseif loose then
        setSerie()
    elseif show_state == 2 then
        if (key:find("kp")) then
            key_num = tonumber(key:sub(3,3))
        else
            key_num = tonumber(key)
        end
        if key_num == serie[ind] then
            ind = ind + 1
            if ind > #serie then
                key_num = 0
                ind = 0
                if love.math.random(30*sped) < #serie then
                    nb_s = nb_s * 0.9
                    sped = sped * 1.111111111
                end
                addElem()
                show_state = 1
                timer = nb_s
            end
        else
            loose = true
        end
    end
end

function love.draw()
    if show_state == 0 then
        love.graphics.print("press any key to start", 790, 330)
    else
        local speed = string.format("speed %.2f", sped)
        love.graphics.print("score: " .. #serie-1 .. "\n" .. speed, 750, 275)
    end
    if loose then
        love.graphics.print("wrong!", 840, 315)
        love.graphics.print("press any key to restart", 785, 330)
    elseif show_state == 2 then
        love.graphics.print("your turn", 830, 330)
    end
    if show_state == 1 and okgo then
        ind = ind + 1
        okgo = false
    end
    if show_state == 1 and ind > #serie then
        ind = 1
        show_state = 2
        timer = 0
        okgo = false
    end
    local i = 1
    local color = {}
    while i <= 9 do
        if show_state == 1 and timer < nb_s and i == serie[ind] or i == key_num then
            color = {.6, .6, .6}
        else
            color = {.2, .2, .2}
        end
        printSerie(i, color)
        i = i + 1
    end
end

function love.update(dt)
    if show_state == 1 then
        timer = timer + dt
        if timer >= 1.5 * nb_s then
            okgo = true
            timer = 0
        end
    end
end
