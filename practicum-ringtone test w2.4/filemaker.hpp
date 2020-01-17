#ifndef _FILEMAKER_HPP
#define _FILEMAKER_HPP

#include "note_player.hpp"

class filemaker : public note_player {
public: 
   filemaker(){}
   
   void start_file();
   void play( const note & n ) override;
   void end_file();
};

#endif
