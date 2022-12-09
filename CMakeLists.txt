cmake_minimum_required(VERSION 3.20)
project(FirstProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FirstProject main.cpp Seat.cpp Seat.h Flight.cpp Flight.h Ticket.cpp Ticket.h User.cpp User.h)
