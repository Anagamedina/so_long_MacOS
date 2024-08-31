cmake_minimum_required(VERSION 3.25.2)
project(so_long_anaa C)

set(CMAKE_C_STANDARD 99)

# Añadir rutas de búsqueda para cabeceras X11 si estás usando XQuartz
if(APPLE)
    include_directories(/opt/X11/include)
    link_directories(/opt/X11/lib)
endif()

# Comando para compilar libmlx.a
add_custom_target(libmlx ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux
        COMMENT "Compilando libmlx.a"
)

# Añadir el ejecutable
add_executable(so_long_anaa
        src/main.c
        src/map_init.c
        includes/so_long.h
        includes/macros.h
        libft/libft.h
        libft/ft_strlen.c
        libft/ft_split.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        src/init_structs.c
        src/handle_errors.c
        src/init_players.c
        src/map_extensions.c
        src/map_items.c
        src/init_game.c
        src/print_functions.c
        minilibx-linux/mlx_int.h
        src/sprites_player.c
        minilibx-linux/mlx_int_wait_first_expose.c
        minilibx-linux/mlx_get_data_addr.c
        minilibx-linux/mlx_screen_size.c
        minilibx-linux/mlx_int_str_to_wordtab.c
        minilibx-linux/mlx_int_set_win_event_mask.c
        minilibx-linux/mlx_clear_window.c
        minilibx-linux/mlx_int_get_visual.c
        minilibx-linux/mlx_destroy_image.c
        minilibx-linux/mlx_string_put.c
        minilibx-linux/mlx_ext_randr.c
        minilibx-linux/mlx_rgb.c
        minilibx-linux/mlx_pixel_put.c
        minilibx-linux/mlx_new_window.c
        minilibx-linux/mlx_flush_event.c
        minilibx-linux/mlx_loop_hook.c
        minilibx-linux/mlx_hook.c
        minilibx-linux/mlx_new_image.c
        minilibx-linux/mlx_int_do_nothing.c
        minilibx-linux/mlx_destroy_window.c
        minilibx-linux/mlx_set_font.c
        minilibx-linux/mlx_put_image_to_window.c
        minilibx-linux/mlx_mouse.c
        minilibx-linux/mlx_loop.c
        minilibx-linux/mlx_int_anti_resize_win.c
        minilibx-linux/mlx_mouse_hook.c
        minilibx-linux/mlx_key_hook.c
        minilibx-linux/mlx_destroy_display.c
        minilibx-linux/mlx_get_color_value.c
        minilibx-linux/mlx_init.c
        minilibx-linux/mlx_xpm.c
        minilibx-linux/mlx_int_param_event.c
        minilibx-linux/mlx_expose_hook.c
)

# Asegurarse de que el target so_long_anaa dependa de libmlx.a
add_dependencies(so_long_anaa libmlx)

# Enlazar el ejecutable con libmlx.a y las bibliotecas X11 o alternativas para macOS
if(APPLE)
    target_link_libraries(so_long_anaa
            ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx.a
            "-framework OpenGL"
            "-framework AppKit"
    )
else()
    target_link_libraries(so_long_anaa
            ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx.a
            X11
            Xext
            Xpm
            Xrandr
    )
endif()
