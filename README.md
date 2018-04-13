# imgui-demo
#Dear imgui 项目配置记录
-------------------------------
##框架简介
dear imgui是一款轻量级的GUI 跨平台框架。
由于原文给的只是源代码，编译环境是基于IDE的项目配置文件，不是很方便。此处我将使用xmake这款轻量级的自动化编译，来构建项目。

##Dear imgui运行环境要求
- **OpenGL2 或者OpenGL3 (此处我使用的是OpenGLES3)**
- **GLFW3库**

##xmake
-- **简介**
之所以使用xmake是因为，相比于cmake, xmake语法更加人性化，配置命令也很简单，可读性很强，强烈推荐。 

-- **一键安装**
```shell
bash <(wget https://raw.githubusercontent.com/tboox/xmake/master/scripts/get.sh -O -)
```


##OpenGL安装
由于imgui 是依赖于OpenGL库的，所以在使用之前会调用libGL.so共享库。文件地址在`/usr/lib/x86_64-linux-gnu/`目录下。有时候可能链接的时候系统没有包含这个目录，需要自己添加这个链接地址。

由于源文件会使用`#include<GL/gl3.h>`但是我是deepin系统，在`/usr/include/GL`这个文件夹下没有找到`gl3.h`只有`gl.h`编译的时候发现很多函数未定义，所以改为`#include<GLES/gl3.h>`发现可以，该头文件包含了需要的函数。

后来百度了一下`OpenGLES` 是`OpenGL`的另一个高性能版本，删除了很多低效的函数（有高性能的版本函数，就不要低性能的函数）。抛弃兼容性来追求最大性能。

##编译imgui时的依赖配置
imgui 依赖`glfw3`这个库，同时`glfw3`也有自己的依赖，所以配置链接文件时的xmake文件也成了关键问题。
glfw3的安装，可以看官网，这里就不做介绍了。主要看`glfw3`的依赖,在安装完`glfw3`库以后，可以通过如下命令，来了解lib的详细信息。
```
cat /usr/local/lib/pkgconfig/glfw3.pc 
```
 [pkg-config 使用记录](https://blog.csdn.net/bryce_xiao/article/details/70787810)
 [pkg-config 详细介绍 强烈推荐](https://blog.csdn.net/exbob/article/details/6991037)


根据以上信息 配置的`xmake.lua`文件

```
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
```

项目编译完成 ,可以愉快的使用imgui啦。

A imgui demo  build by xmake
