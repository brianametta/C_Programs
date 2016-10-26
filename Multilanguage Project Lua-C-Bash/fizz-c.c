#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Assignment #5-1, Briana Wright, masc1429\n");

    int s=0;

    //open
    lua_State *L = luaL_newstate();

    // load the libs
    luaL_openlibs(L);

    //run a Lua script here
    luaL_dofile(L,argv[1]);

    //close
    lua_close(L);

    return 0;
}