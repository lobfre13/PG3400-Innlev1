#define BILLION 1E9;

void benchmark (int times, char sortAlgorythm) {
	print("Result:\n" +
		"Merge sort: " + getAverage(times, 'm') + "\n" +
		"Insertion sort: " + getAverage(times, 'i') + "\n" +
		"Selection sort: " + getAverage(times, 's') + "\n" +
		"Bubble sort: " + getAverage(times, 'b') + "\n" + 
		"Quicksort: " + getAverage(times, 'q') + "q"
		);
}

/*http://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/qnx/clock_gettime.html*/
double getAverage (int times, char sortAlgorythm) {
	double timeEllapsed = 0.0;
	for (int i = 0; i < times; i++) {
		struct timespec start, stop;
    	double accum;

    	initArray(&numbers, 100);
		readFile("resources/2.txt");

    	if( clock_gettime( CLOCK_REALTIME, &start) == -1 ) {
      	perror( "clock gettime" );
      	exit( EXIT_FAILURE );
    	}

    	sort(sortAlgorythm);

    	if( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) {
      		perror( "clock gettime" );
      		exit( EXIT_FAILURE );
    	}

    	accum = ( stop.tv_sec - start.tv_sec )
          + ( stop.tv_nsec - start.tv_nsec )
            / BILLION;
    	printf( "%lf\n", accum );
		
		timeEllapsed += accum;
		free(numbers.array); 
	}
	return timeEllapsed / times;
}