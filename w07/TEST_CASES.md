# Test Cases for Motor Vehicle and Truck Management System

This document outlines the test cases for validating the functionalities of the Motor Vehicle and Truck Management System.

---

## Test Case 1: Vehicle Initialization

- **Description:** Verify if a `MotorVehicle` object is created with the correct initial values.
- **Input:** License Plate: `VVV-111`, Year: `2010`
- **Expected Output:**
  ```
  | 2010 | VVV-111 | Factory
  ```
- **Status:** Pass

---

## Test Case 2: Moving Vehicle to New Location

- **Description:** Check if the `MotorVehicle` correctly updates its location when `moveTo` is called.
- **Input:** Move Vehicle to `Downtown Toronto`
- **Expected Output:**
  ```
  |   VVV-111| |             Factory ---> Downtown Toronto           |
  ```
- **Status:** Pass

---

## Test Case 3: Creating a Truck

- **Description:** Verify if a `Truck` object is created with the correct initial values, including capacity.
- **Input:** License Plate: `T-1111`, Year: `2015`, Capacity: `5432`, Address: `Toronto HQ`
- **Expected Output:**
  ```
  | 2015 | T-1111 | Toronto HQ | 0.0/5432
  ```
- **Status:** Pass

---

## Test Case 4: Loading Cargo onto Truck

- **Description:** Ensure that `addCargo` adds weight correctly without exceeding capacity.
- **Input:** Add Cargo: `2000`
- **Expected Output:**
  ```
  Cargo loaded!
  | 2015 | T-1111 | Toronto HQ | 2000.0/5432
  ```
- **Status:** Pass

---

## Test Case 5: Exceeding Cargo Capacity

- **Description:** Verify that the truck does not exceed its maximum capacity.
- **Input:** Add Cargo: `6000`
- **Expected Output:**
  ```
  Adding cargo failed!
  | 2015 | T-1111 | Toronto HQ | 5432.0/5432
  ```
- **Status:** Pass

---

## Test Case 6: Unloading Cargo from Truck

- **Description:** Check if `unloadCargo` correctly empties the truck’s cargo.
- **Input:** Unload Cargo
- **Expected Output:**
  ```
  Cargo unloaded!
  | 2015 | T-1111 | Toronto HQ | 0.0/5432
  ```
- **Status:** Pass

---

## Test Case 7: Input Validation

- **Description:** Validate that incorrect inputs for license plate or capacity are handled gracefully.
- **Input:** License Plate: `123456789` (Exceeds 8 characters)
- **Expected Output:** Error or truncated value.
- **Status:** Pass

---

## Test Case 8: User Interaction for Read/Write

- **Description:** Ensure user can interact with objects using `cin` and `cout`.
- **Input:** License Plate: `ABC-123`, Year: `2020`, Address: `Mississauga`
- **Expected Output:**
  ```
  | 2020 | ABC-123 | Mississauga
  ```
- **Status:** Pass

---

Feel free to expand or modify these test cases as needed. Ensure all edge cases and invalid inputs are properly tested.
