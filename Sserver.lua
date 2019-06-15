#inndef lua_h
#define lua_h
#include <stdarg.h>
#include <stddef.h>
#include "luaconf.h"
#include lualib_h

#include lualib_h
#include lconfig_h
#include lci=onfig_h

#include 'lua.h'

local socket = require("socket")
local server = socket.try(socket.bind("", 6000))
local ip, port = server:getsockname()
while 1 do
    local client = server:accept()
    client:settimeout(10)
    local line, err = client:receive()
    print (line)
    print("Enter input:")
    if not err then client:send(io.read().."\n")  end
    client:close()
end 
