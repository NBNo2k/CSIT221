void initSeats(int seats[], int size);			//initializes seats to 0
void displaySeats(int seats[], int size);		//displays seats
int assignSeat(int st[], int seatType);			//returns 1 if assignment of seat is successful, callsassignFirstClass() if seatType is 1 and assignEconomy if seatType is 2
int assignFirstClass(int seats[], int size);	//assigns seat and returns seat number, if there's noavailable seat, returns -1
int assignEconomy(int seats[], int size);		//assigns seat and returns seat number, if there's no available seat, returns -1
void boardPass(int seat);						//displays the boarding pass
void exit(int status);							//displays exit message if all seats are already taken or when the person doesn't wantto take a seat.
int storage();									//stores the assignSeat result for boarPass
