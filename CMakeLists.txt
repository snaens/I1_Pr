cmake_minimum_required(VERSION 4.1)
project(I_Pr C)

set(CMAKE_C_STANDARD 23)

add_executable(1-1 "1.1.menue.c")
add_executable(2-1 "2.1.alle_datentypen.c")
add_executable(2-2 "2.2.bereichsueberlauf.c")
add_executable(5-2-1 "5.2.1.mathematische ausdruecke.c")
add_executable(5-2-2 "5.2.2.kettenbruck_pi.c")
add_executable(5-4-1 "5.4.1.logische_operatoren.c")
add_executable(5-5-1 "5.5.1.ueberpruefungen mit bit-operatoren.c")
add_executable(5-6-1 "5.6.1.vertauschen von zwei bytes.c")
add_executable(5-6-2 "5.6.2.duale ausgabe eines bytes.c")
add_executable(6-1-1 "6.1.1.volumen und oberflaeche einer kugel.c")
target_link_libraries(6-1-1 m) #math.h lib
