#include <iostream>
#include <fstream>

#include "L1208_475.hpp"

using namespace std;
int solution_count;

void solution_count_update(TSP_Solution* s, TSP_Instance* t) {
	solution_count = solution_count + 1;
	if ((solution_count == 1) || ((solution_count % PRINT_FREQUENCY) == 0)) {
		printf("%d %7.1f\n", solution_count, solution_cost(s, t));
	}
}

void anneal(TSP_Instance* t, TSP_Solution* s) {
	int x, y;                       /* пара точек для перестановки */
	int i, j;                       /* счетчики */
	bool accept_win, accept_loss;   /* условия принятия перехода */
	double temperature;             /* текущая температура системы */
	double current_value;           /* текущее значение */
	double start_value;             /* значение на момент начала цикла */
	double delta;                   /* значение после обмена */
	double exponent;                /* показатель степени для функции энерг. состояния */

	temperature = INITIAL_TEMPERATURE;

	initialize_solution(t->n, s);
	current_value = solution_cost(s, t);

	for (i = 1; i <= COOLING_STEPS; i++) {
		temperature *= COOLING_FRACTION;

		start_value = current_value;

		for (j = 1; j <= STEPS_PER_TEMP; j++) {
			/* выбор индексов элементов для обмена местами */
			x = random_int(1, t->n);
			y = random_int(1, t->n);

			delta = transition(s, t, x, y);
			accept_win = (delta < 0);       /* снизил ли обмен стоимость? */

			exponent = (-delta / current_value) / (K * temperature);
			accept_loss = (exp(exponent) > random_float(0, 1));

			if (accept_win || accept_loss) {
				current_value += delta;
			}
			else {
				transition(s, t, x, y);     /* обратное перестановка в случае неудачи */
			}
			solution_count_update(s, t);
		}

		if (current_value < start_value) {  /* повторяем при этой температуре */
			temperature /= COOLING_FRACTION;
		}
	}
}

void repeated_annealing(TSP_Instance* t, int nsamples, TSP_Solution* bestsol) {
	TSP_Solution s;
	double best_cost;
	double cost_now;
	int i;

	initialize_solution(t->n, &s);
	best_cost = solution_cost(&s, t);
	copy_solution(&s, bestsol);

	for (i = 1; i <= nsamples; i++) {
		anneal(t, &s);
		cost_now = solution_cost(&s, t);
		if (cost_now < best_cost) {
			best_cost = cost_now;
			copy_solution(&s, bestsol);
		}
	}
	cout << "BEST COST " << best_cost;
}


int main()
{
	TSP_Instance problem;
	TSP_Solution solution;

	int i = 0;
	ifstream in("test.txt");
	if (in.is_open())
	{
		int x, y;
		while (in >> x >> y && i <= 1001)
		{
			problem.point_array[i].x = x;
			problem.point_array[i].y = y;
			i++;
		}
	}
	in.close();
	problem.n = i;

	repeated_annealing(&problem, 10, &solution);
}