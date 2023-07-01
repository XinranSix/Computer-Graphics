add_rules("mode.debug", "mode.release")

-- add_linkdirs("./lib")
add_includedirs("./include")
set_languages("cxx20")

target("InOneWeekend")
    set_kind("binary")
    add_files("./src/InOneWeekend/*.cpp")

-- target("imgui")
--     set_kind("static")
--     add_files("./imgui/*.cpp")

-- target("Renderer")
--     set_kind("static")
--     add_files("./Renderer/*.cpp")

-- target("Camera")
--     set_kind("static")
--     add_files("./Camera/*.cpp")
