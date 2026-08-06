add_rules("mode.debug", "mode.release")

set_languages("cxx20")

set_arch("x64")

set_policy("check.auto_ignore_flags", false)

set_objectdir("D:\\.objs")

target("version")
    set_kind("shared")

    add_files(
        "src/*.cpp"
    )

    add_headerfiles(
        "src/*.hpp"
    )

    add_includedirs(
        ".",
        "src"
    )

    add_syslinks(
        "user32",
        "kernel32",
        "dinput8",
        "dbghelp"
    )

    set_targetdir("D:\\build")