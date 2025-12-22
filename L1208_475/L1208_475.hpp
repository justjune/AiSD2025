int const PRINT_FREQUENCY = 10000;
int const COOLING_STEPS = 1000;
int const STEPS_PER_TEMP = 1000;
int const INITIAL_TEMPERATURE = 1;
double const COOLING_FRACTION = 0.998;
double const K = 0.01;

struct Point
{
	int x;
	int y;
};

struct TSP_Instance
{
	int n;
	Point point_array[1002];
};

struct TSP_Solution
{
	double cost;
	int n;
	int index_array[1002];
};

void initialize_solution(int n, TSP_Solution* s);
void swap(int* a, int* b);
int random_int(int low, int high);
double random_float(int low, int high);
int sq(int x);
double distance(TSP_Solution* s, int x, int y, TSP_Instance* t);
double solution_cost(TSP_Solution* s, TSP_Instance* t);
void copy_solution(TSP_Solution* s, TSP_Solution* t);
double transition(TSP_Solution* s, TSP_Instance* t, int i, int j);
