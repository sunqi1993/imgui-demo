-- the debug mode
if is_mode("debug") then
    
    -- enable the debug symbols
    set_symbols("debug")

    -- disable optimization
    set_optimize("none")
end  



target("imgui")
    set_kind("shared")
    add_linkdirs("/usr/lib/x86_64-linux-gnu/","/usr/local/lib")
    -- 添加链接的lib名称
    add_links("glfw3","GL","Xrandr","X11","Xi","Xxf86vm","pthread","dl","Xinerama","m","rt","Xcursor")
    
    add_headers("src/imgui/*.h")
    add_files("src/imgui/*.cpp")

target("hello")

    set_kind("binary")

    -- 添加链接的目录 方便ld寻找
    -- add_linkdirs("/usr/lib/x86_64-linux-gnu/","/usr/local/lib")
    -- 添加链接的lib名称
    -- add_links("glfw3","GL","Xrandr","X11","Xi","Xxf86vm","pthread","dl","Xinerama","m","rt","Xcursor")

    add_headers("src/imgui/*.h")
    -- add files
    add_files("src/main.cpp") 

    add_deps("imgui")