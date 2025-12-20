#include <iostream>
#include <fstream>

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

void initialize_solution(int n, TSP_Solution* s) {
	int i;

	s->n = n;
	for (i = 1; i <= n; i++) {
		s->index_array[i] = i;
	}
}

void swap(int* a, int* b) {
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

int random_int(int low, int high) {                 /* lower/upper bounds on numb*/
	int i, j, r;                                    /* random number*/

	i = RAND_MAX / (high - low + 1);
	i *= (high - low + 1);
	while ((j = rand()) >= i) {
		continue;
	}
	r = (j % (high - low + 1)) + low;
	if ((r < low) || (r > high)) {
		printf("Error: random integer %d out of range [%d,%d]\n",
			r, low, high);
	}
	return(r);
}

double random_float(int low, int high) {       /*lower/upper bounds on numb*/
	double i, j;                               /* avoid arithmetic trouble */
	double r;                                  /* random number*/

	i = RAND_MAX / (high - low);
	i *= (high - low);
	while ((j = rand()) >= i) {
		continue;
	}
	r = (j / i) * (high - low) + low;

	if ((r < low) || (r > high)) {
		printf("ERROR: random real %f out of range [%d,%d]\n",
			r, low, high);
	}
	return(r);
}

int sq(int x) {
	return(x * x);
}

double distance(TSP_Solution* s, int x, int y, TSP_Instance* t) {
	int i, j;

	i = x;
	j = y;

	if (i == ((t->n) + 1)) {
		i = 1;
	}

	if (j == ((t->n) + 1)) {
		j = 1;
	}

	if (i == 0) {
		i = (t->n);
	}

	if (j == 0) {
		j = (t->n);
	}

	return (sqrt((double)(sq(t->point_array[(s->index_array[i])].x - t->point_array[(s->index_array[j])].x) +
		sq(t->point_array[(s->index_array[i])].y - t->point_array[(s->index_array[j])].y))));
}

double solution_cost(TSP_Solution* s, TSP_Instance* t) {
	int i;           /* counter */
	double cost;     /* cost of solution */

	cost = distance(s, t->n, 1, t);
	for (i = 1; i < (t->n); i++) {
		cost = cost + distance(s, i, i + 1, t);
	}

	return(cost);
}

void copy_solution(TSP_Solution* s, TSP_Solution* t) {
	int i;    /* counter */
	t->n = s->n;
	for (i = 1; i <= (s->n); i++) {
		t->index_array[i] = s->index_array[i];
	}
}

double transition(TSP_Solution* s, TSP_Instance* t, int i, int j) {
	double was, willbe;    /* before and after costs */
	bool neighbors;        /* i,j neighboring tour positions? */

	neighbors = false;

	if (i == j) {
		return(0.0);
	}

	if (i > j) {
		return(transition(s, t, j, i));
	}

	if (i == (j - 1)) {
		neighbors = true;
	}

	if ((i == 1) && (j == (s->n))) {
		swap(&i, &j);
		neighbors = true;
	}

	if (neighbors) {
		was = distance(s, i - 1, i, t) + distance(s, j, j + 1, t);
	}
	else {
		was = distance(s, i - 1, i, t) + distance(s, i, i + 1, t)
			+ distance(s, j - 1, j, t) + distance(s, j, j + 1, t);
	}

	swap(&(s->index_array[i]), &(s->index_array[j]));

	if (neighbors) {
		willbe = distance(s, i - 1, i, t) + distance(s, j, j + 1, t);
	}
	else {
		willbe = distance(s, i - 1, i, t) + distance(s, i, i + 1, t)
			+ distance(s, j - 1, j, t) + distance(s, j, j + 1, t);
	}

	return(willbe - was);
}
