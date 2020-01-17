#include <iostream>
#include <fstream>
#include "filemaker.hpp"

void filemaker::start_file(){
    std::ofstream myfile;
        myfile.open ("melody.cpp", std::ofstream::out | std::ofstream::trunc);
        myfile << "#ifndef _GENERATED_HPP\n";
		myfile << "#define _GENERATED_HPP\n";
		myfile << "\n";
        myfile << "#include \"melody.hpp\"\n";
        myfile << "\n";
        myfile << "class generated : public melody {\n";
        myfile << "public:\n";
        myfile << "    void play( note_player & p ){\n";
        myfile.close();
}

void filemaker::play( const note & n ){
   if( n.frequency != 0 ){ 
       std::ofstream myfile;
        myfile.open ("melody.cpp", std::ofstream::app);
        myfile << "        p.play( note{ " << n.frequency << ",  " << n.duration << " } );\n";
        myfile.close();
   }   
}


void filemaker::end_file(){
    std::ofstream myfile;
        myfile.open ("melody.cpp", std::ofstream::app);
        myfile << "    }\n";
        myfile << "};\n";
        myfile << "\n";
        myfile << "#endif\n";
        myfile.close();
}