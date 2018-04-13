
{
    ["includes"] = 
    {
        "src/main.cpp"
    ,   "build/imgui.h"
    ,   "build/imconfig.h"
    ,   "build/imgui_impl_glfw_gl3.h"
    }

,   ["program"] = "gcc"
,   ["sources"] = 
    {
        "src/main.cpp"
    }

,   ["flags"] = 
    {
        "-g"
    ,   "-O0"
    ,   "-Ibuild"
    ,   "-m64"
    ,   "-I/usr/local/include"
    ,   "-I/usr/include"
    }

}
