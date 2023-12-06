

# Dining Philosophers Simulation

This project includes two programs, one for the mandatory part and another for the bonus part, both simulating the classic Dining Philosophers problem. The programs are designed to comply with specific rules and requirements.

## Mandatory Part - Philo

### Description


The `philo` program implements the Dining Philosophers problem using threads and mutexes. Each philosopher is a thread, and the forks are protected by mutexes to prevent conflicts.

### Build

To build the program, run the following command:
```bash 
make
```
### Run
To run the program, use the following command:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
### Arguments
* number_of_philosophers: The number of philosophers and forks.
* time_to_die: Time in milliseconds. If a philosopher doesn’t start eating within this time after the last meal or simulation starts, they die.
* time_to_eat: Time in milliseconds. The time it takes for a philosopher to eat.
* time_to_sleep: Time in milliseconds. The time a philosopher spends sleeping.
* number_of_times_each_philosopher_must_eat (optional): If specified, the simulation stops when all philosophers have eaten this many times. If not specified, the simulation stops when a philosopher dies.

### Logs
The program generates logs in the specified format:

timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died

## Bonus Part - philo_bonus

### Description
The philo_bonus program is the bonus part of the project, implementing the Dining Philosophers problem with processes and semaphores. All forks are placed in the middle of the table, and each philosopher is a separate process.

### Build

To build the program, run the following command:
```bash 
make bonus
```
### Run
To run the program, use the following command:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
## Resources 
* Philo problem: https://en.wikipedia.org/wiki/Dining_philosophers_problem  
* threads: you can check this playlist https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM

