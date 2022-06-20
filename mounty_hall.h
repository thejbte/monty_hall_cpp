


#define LOSER()         " _                     ""\n"\
                        "| |                    ""\n"\
                        "| | ___  ___  ___ _ __ ""\n"\
                        "| |/ _ \\/ __|/ _ \\ '__|""\n"\
                        "| | (_) \\__ \\  __/ |   ""\n"\
                        "|_|\\___/|___/\\___|_|   ""\n"
                      
#define WINNER()        "         (_)                      ""\n"\
                        "__      ___ _ __  _ __   ___ _ __ ""\n"\
                        "\\ \\ /\\ / / | '_ \\| '_ \\ / _ \\ '__|""\n"\
                        " \\ V  V /| | | | | | | |  __/ |   ""\n"\
                        "  \\_/\\_/ |_|_| |_|_| |_|\\___|_|   ""\n"

#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"


class simulation {
    const int GOAT = 0;
    const int CAR  = 1;
    static const int MAX_NUM_DOOR = 3;
    private:
        int doorGuest, doorHost;
        int doors[MAX_NUM_DOOR] = {GOAT, GOAT, GOAT} ; // random
        int doorsSelected[MAX_NUM_DOOR] = {GOAT, GOAT, GOAT} ;
        int doorsGuestAux[MAX_NUM_DOOR] = {-1, -1, -1} ;
        int randomGenerator(void);
    public:
        simulation();
        /**
         * @brief generator from hide doors aleatory
        */
        void generatorDoors (void);

        int getDoorFromGuest (void);

        int openDoorFromHost (void);

        bool iSselectDoorWinner(int);

        bool iSselectDoorFromHostAGoat(int);

        void print(void);

        void printDoorsClose(void);

        void printDoorsFromPosition(int pos, int shape);
        void printDoorsFromPosition(void);
        void printDoorsAll(void);
        
        void patternSelector(int value);
        void patternClose(void);
        void patternCloseAndSelected(void);
        

};