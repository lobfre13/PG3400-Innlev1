#ifndef STATICSTRINGS
#define STATICSTRINGS

#define BENCHMARK_HEADER "Benchmarking average of a thousand sorts:\n"
#define NUMBER_NOT_FOUND "Did not find number %d in the selected file.\n"
#define NUMBER_FOUND "Found number %d in index %d.\n"

#define SHORT_ARGUMENTS "mbisq"

#define REQUEST_VALID_FILE_PATH "Please enter a valid file path: "
#define REQUEST_INTEGER "Please enter a valid integer to search for: "
#define REQUEST_SORT_ALGORITHM "Please enter your choice of sorting algorithm:\n" \
								"-m (merge sort)\n" \
								"-b (bubble sort)\n" \
								"-s (selection sort)\n" \
								"-i (insertion sort)\n" \
								"-q (quicksort)\n" \
								"Your choice: "
#define HELPER_TEXT "HELPER MENU - mbisq\n" \
								"Welcome to mbisq w/benchmarks! Enjoy your stay!\n"	\
								"Usage:\t\tmbisq [filepath] -[sort algorithm] [number]\n" \
								"\t\tmbisq --help\n" \
								"\t\tmbisq --bench\n" \
								"\t\tmbisq --bench=[arraySize]\n" \
								"\t\tmbisq\t\t(Interactive mode)\n\n" \
								"Available flags:\n\n" \
								"--help\t\tDisplay the help and exit\n"	\
								"--bench\t\tRun a test of the sort algorithms and display the results\n" \
								"-m\t\tUse the merge sort algorithm\n" \
								"-b\t\tUse the bubble sort algorithm\n" \
								"-i\t\tUse the insertion sort algorithm\n" \
								"-s\t\tUse the selection sort algorithm\n" \
								"-q\t\tUse the quicksort algorithm\n\n" \

#endif