#include <time.h>

#include "../include/dp.hpp"
#include "../include/qlearning.hpp"
#include "../include/montecarlo.hpp"

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	int height = 2;
	int width = 1;
	int battery = 3;
	cleaner::world w(width, height, battery);

//	cleaner::dp dp_solver(w, 0.001, 0.99);
//	dp_solver.solve();
//	std::cout << "dp_solver(" << *w.getState(0) << ") = " << dp_solver.getValueAt(0) << std::endl;

	for(int episode = 1; episode <= 10; episode++) {
		cleaner::montecarlo mc_solver(w, 0.1, 0.99, 0.1, episode * 1000);
		mc_solver.solve();
		std::cout << "mc_solver(" << *w.getState(0) << ") = " << mc_solver.getFeatValueAt(0) << std::endl;

		cleaner::qlearning q_solver(w, 0.1, 0.1, 0.99, episode * 1000);
		q_solver.solve();
		std::cout << "q_solver(" << *w.getState(0) << ") = " << q_solver.getFeatValueAt(0) << std::endl;
	}

	return 0;
}
