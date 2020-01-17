#include "hwlib.hpp"
#include "note_printer.hpp"


void note_printer::play(const note & n){
    hwlib::cout << "duration = " << n.duration << "\n";
    hwlib::cout << "frequency = " << n.frequency << "\n";
}