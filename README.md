# Hostel Management System

## Overview

This project is a C++ based Hostel Management System that allows for the management of hostel room bookings, cancellations, and upgrades. The system simulates a hostel with three floors, each containing several rooms. It provides functionalities to book rooms for one to three people, display the current status of rooms, cancel bookings, and upgrade bookings.

## Features

- **Room Booking**: Allows users to book a room for one, two, or three people.
- **Display Status**: Displays the current status of all rooms, indicating whether they are vacant or occupied.
- **Cancel Booking**: Provides the functionality to cancel a booking by removing a person's name from the room.
- **Upgrade Booking**: Allows updating the name of a person in the booking.

## Classes

- **Node Class**: Represents each room in the hostel, including attributes such as room capacity (`num`), filled capacity (`fill`), occupant names (`name`), and pointers to the next and previous rooms (`next` and `prev`).

- **Hostel Class**: Manages the hostel operations, including creating the rooms, displaying room status, booking rooms, canceling bookings, and upgrading bookings.

## Usage

- **Create Rooms**: The `create` method initializes the hostel with predefined room capacities across three floors.
- **Book Rooms**: The `book` method allows booking rooms by specifying the number of people and their names.
- **Display Rooms**: The `display` method shows the current status of each room on each floor.
- **Cancel Bookings**: The `cancel` method allows removing a person's booking by specifying the floor, room number, and occupant's name.
- **Upgrade Bookings**: The `upgrade` method allows updating an occupant's name by specifying the floor, room number, and old and new names.

## How to Run

1. Clone the repository:
   ```git clone https://github.com/yourusername/HostelManagementSystem.git```
2. Navigate to the project directory:
```cd HostelManagementSystem```
3. Compile the program:
   ```g++ hostel_management.cpp -o hostel_management```
4. Run the executable:
```./hostel_management```
