#include "hwlib.hpp"
#include "note_player_melody_generator.hpp"

note_player_melody_generator::note_player_melody_generator() {

	const std::string header = 
	"#include \"meldody.hpp\"\n\n"
	"meldody:play(note_player & p) {";
	std::ofstream outfile ("meldody.cpp");
	outfile << header << std::endl;
	outfile.close();
}
void note_player_melody_generator::play( const note & n ){
    std::ofstream outfile;
    outfile.open("meldody.cpp", std::ios_base::app);
    outfile << "\tp.play( note{ " << n.frequency << ",  " << n.duration << " } );\n";
    outfile.close();
}
void note_player_melody_generator::close() {
    std::fstream outfile;
    outfile.open("meldody.cpp", std::ios_base::app);
    outfile << "}";
    outfile.close();
}