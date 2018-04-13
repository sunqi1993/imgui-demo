
{
    ["program"] = "g++"
,   ["objectfiles"] = 
    {
        "build/.objs/hello/src/main.cpp.o"
    }

,   ["flags"] = 
    {
        "-Lbuild"
    ,   "-L/usr/lib/x86_64-linux-gnu/"
    ,   "-L/usr/local/lib"
    ,   "-Wl,-rpath=$ORIGIN"
    ,   "-g"
    ,   "-limgui"
    ,   "-lglfw3"
    ,   "-lGL"
    ,   "-lXrandr"
    ,   "-lX11"
    ,   "-lXi"
    ,   "-lXxf86vm"
    ,   "-lpthread"
    ,   "-ldl"
    ,   "-lXinerama"
    ,   "-lm"
    ,   "-lrt"
    ,   "-lXcursor"
    ,   "-m64"
    ,   "-L/usr/lib"
    }

}
