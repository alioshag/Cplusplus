//Homework INFO1-CE9264
//date: 10/01/2012
//name: Aliosha Gonzalez
//user: ag1917
//filename: plot-homework.C


/*
"The Official Movie Plot Generator" by Jason and Justin Heimberg
http://www.movieplotgenerator.com/
*/

#include <iostream>
#include <cstdlib>	//for srand, rand, RAND_MAX
#include <ctime>	//for time
#include <string>
using namespace std;

struct subject_array {
        size_t number;  //0 for singular and 1 for plural
        string subject; 
};

int main()
{
	/*
	Although the three arrays just happen to have the same number of
	elements, they are not parallel arrays.
	*/

	const subject_array subject[] = {                        //array of struct
                {0, "A cop who doesn't play by the rules"},
                {0, "A single mom"},
                {1, "Three naughty nurses"},
                {0, "An adorable panda cub"},
                {0, "A ruthless Mafia kingpin"},
                {0, "An ancient and powerful wizard"},
                {0, "A fraternity of lovable slobs, misfits, and drunks"},
                {0, "Adolph Hitler"},
                {0, "From a land where honor and tradition reign, "
			"comes the legend of a Samurai who"},
                {0, "A bumbling nerd"},
                {0, "Bigfoot"},
                {0, "A crackhead"},
                {0, "A flamboyantly gay hairdresser"},
                {0, "A retarded boy"},
                {1, "America's founding fathers"},
                {0, "A hockey mask-wearing psychopath"},
                {0, "A gangsta rapper"},
                {0, "An unrefined but precocious orphan girl"},
                {0, "The ultimate crime-fighting indestructible cyborg"},
                {1, "The Sesame Street puppets"},
                {0, "A small-town girl with big-time dreams"},
                {0, "A group of orthodox rabbis"},
                {0, "A burned-out hippie"},
                {0, "A Catholic priest"},
                {0, "A hooker with a heard of gold"},
                {0, "A grumpy midget"},
                {0, "A group of cantankerous senior citizens"},
                {0, "Jesus"},
                {0, "A no-nonsense Army drill sergeant"},
                {0, "A macho NFL quarterback"},
                {1, "Desperate C programmers"},    //My two additions to the array
                {1, "A cuban political prisoner dreams to arrive to the land of freedom while Fidel and Raul Castro"}
        };
        
	const size_t nsubject = sizeof subject / sizeof subject[0]; //number of struct

	const string predicate[][2] = {
                {"fights crime", "fight crime"}, 
                {"raises a baby", "raise a baby"},
                {"discovers the wonders of self pleasure", "discover the wonders of self pleasure"},
                {"befriends the creatures of the forest", "befriend the creatures of the forest"},
                {"is on the run from the Mob", "are on the run from the Mob"},
                {"quests for a dragon's treasure", "quest for a dragon's treasure"},
                {"indulges in beer bashes, toga parties, and an assortment of ill-advised high junks",
                        "indulge in beer bashes, toga parties, and an assortment of ill-advised high junks"},
                {"invades Poland", "invade Poland"},
                {"takes on an army of evil Ninjas", "take on an army of evil Ninjas"},
                {"becomes immersed in hip-hop culture", "become immersed in hip-hop culture"},
                {"becomes a nanny for a conservative aristocratic family", 
                        "become a nanny for a conservative aristocratic family"},
                {"coaches a hapless Little League baseball team", "coach a hapless Little League baseball team"},
                {"hits the Karaoke circuit", "hit the Karaoke circuit"},
                {"grows 50 times in size and go on a destructive rampage",	
                        "grow 50 times in size and goes on a destructive rampage"},
                {"travels through time", "travel through time"},
                {"hacks up coeds with a rusty machete",	"hack up coeds with a rusty machete"},
                {"becomes a pimp", "become pimps"},
                {"challenges the social mores of upper class society",
                        "challenge the social mores of upper class society"},
                {"commands a fleet of starships against a horde of insectoid aliens",	
                        "command a fleet of starships against a horde of insectoid aliens"},
                {"helps children learn to read", "help children learn to read"},
                {"gets transformed into a gorgeous sexpot", "get transformed into gorgeous sexpots"},
                {"competes in gritty inner-city street basketball tournaments",	
                        "compete in gritty inner-city street basketball tournaments"},
                {"goes on an LSD-induced psychedelic adventure", "go on an LSD-induced psychedelic adventure"},
                {"discovers a hidden talent for dance", "discover a hidden talent for dance"},
                {"struggles to get off heroin",	"struggle to get off heroin"},
                {"tries to lose (his/her/their) virginity", "try to lose (his/her/their) virginity"},
                {"battles problem flatulence",	"battle problem flatulence"},
                {"rises from the grave", "rise from the grave"},
                {"rescues a group of American P.O.W.'s", "rescue a group of American P.O.W.'s"},
                {"comes out of the closet", "come out of the closet"},
                {"plays the hula hoop at a RNC",              //my addition to the array
                        "play the hula hoop at a RNC"}
	};
	const size_t npredicate = sizeof predicate / sizeof predicate[0]; //numer of rows

	const string modifier[] = {       
                "with a mischievous orangutan",
                "while juggling work, parenthood, "
			"and finding personal fulfillment",
		"in two hours of the raunchiest hardcore porno action "
			"ever seen",
		"in this heartwarming animated adventure",
		"in the heart of the Amish country",
		"with a cunning elf, an obese ogre, and a belligerent dwarf",
		"despite being admonished by a crusty old dean",
		"in this documentary narrated by James Earl Jones",
		"in an action-packed epic filled with elaborate, "
			"acrobatic Kung-Fu fight sequences",
		"to win the heart of the high school dreamboat",
		"in the feel-good comedy of the year",
		"in order to pay off a gambling debt",
		"in a beat-up Buick",
		"in the middle of Downtown Tokyo "
			"(in Japanese with English subtitles)",
		"with a wise-cracking robot",
		"in a blood-filled teen slasher",
		"deep in the Compton ghetto",	//Los Angeles
		"in 1954 Baltimore "
			"(based on the Pulitzer Prize winning novel)",
		"shown in spectacular 3-D Imax",
		"in this powerful after school special",
		"set to an all-star '80's soundtrack "
			"featuring Air Supply, Journey, and Survivor",
		"to save the local synagogue",
		"with a magical talking bong, "
		"in this stoner cult classic",
		"in a rousing adaptation of the Broadway musical",
		"with the help of former tennis great Ivan Lendl "
			"(based on a true story)",
		"with the help of the ghost of Elvis",
		"set against the backdrop "
			"of a Florida retirement community",
		"in the inspiring story loosely adapted from the Bible",
		"in a Vietnamese prison camp",
		"and in the process "
			"learn(s) the true meaning of Christmas",
	};
	const size_t nmodifier = sizeof modifier / sizeof modifier[0];

	srand(static_cast<unsigned>(time(0)));
        
        int pick_subject = rand() % nsubject;
        
        cout << subject[pick_subject].subject << "\n"
		<< predicate[rand() % npredicate][subject[pick_subject].number] << "\n"
		<< modifier[rand() % nmodifier] << ".\n";
	
        
        return EXIT_SUCCESS;
}
