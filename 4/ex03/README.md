## Core Components

### AMateria System

The materia system is based on the abstract `AMateria` class:
- Base class for specific materias like `Ice` and `Cure`
- Provides virtual methods that derived classes must implement
- Handles type identification and basic functionality

### Character Inventory

Characters can equip up to 4 materias:
- Simple array-based inventory system
- First-empty-slot equipping logic
- Safe unequipping that preserves materia instances
- Deep copying of character state including inventory

### MateriaSource

The `MateriaSource` class serves as a "factory" for materias:
- Can learn up to 4 materia templates
- Creates new copies of previously learned materias
- Returns NULL for unknown materia types

This implementation follows
```
Factory Method pattern
- Creates new materias based on type
- Factory interface defines creation method
- Concrete factory (MateriaSource) implements creation logic
```
```
Prototype Pattern
- Each concrete materia can clone itself
- New instances created by copying prototypes
- Used within the factory implementation
```

### Floor Management System

A unique linked list implementation to track unequipped materias:
- Prevents memory leaks when materias are unequipped
- Uses static members to track and clean up at program end
- Properly handles character destruction order

## Edge Cases Covered

1. **Null Pointers**
   - Passing NULL to equip/unequip/learn functions
   - Creating materias of unknown types

2. **Boundary Conditions**
   - Full inventory management
   - Full materia source management
   - Invalid inventory indices
   - Floor handling with multiple unequips

3. **Memory Management**
   - Deep copying of characters and their inventories
   - Proper cleanup of floor materias
   - No memory leaks on program exit
   - Character destruction order handling

4. **Character Interaction**
   - Multiple characters interacting with floor materias
   - Character copies using materias properly

5. **Stress Testing**
   - High-volume materia creation/unequipping
   - Floor management under heavy load

## Test Explanations

### Test 1: Basic Functionality
Verifies the core features work correctly:
- Learning materias
- Creating new materias
- Equipping character
- Using materias on targets

### Test 2: MateriaSource Edge Cases
Tests the limits of the materia source:
- Full storage handling
- NULL materia learning
- Unknown materia type requests

### Test 3: Character Inventory Limits
Ensures inventory constraints are enforced:
- Full inventory detection
- Proper cleanup when equip fails

### Test 4: Unequip Functionality
Tests unequipping behavior:
- Successful unequipping
- Empty slot handling
- Invalid index handling

### Test 5: Deep Copy Test
Verifies that character copies maintain independent inventories:
- Deep copying of all materias
- Proper functionality after copying

### Test 6: Use Edge Cases
Tests the limits of materia usage:
- Invalid indices
- Empty slot usage attempts

### Test 7: Floor Management
Tests the floor system's ability to track unequipped materias:
- Multiple unequip operations
- New character interaction with floor materias

### Test 8: Floor Array Limits
Stress tests the floor management system:
- High volume of equip/unequip operations
- Circular buffer behavior for floor storage

### Test 9: Character Tracking System
Demonstrates the importance of character reference counting:
- Multiple characters sharing access to floor materias
- Progressive deletion of characters in sequence
- Verification that floor materias persist until last character
- Proper cleanup only when the last character is destroyed
- Prevention of both premature deletion and memory leaks

## Implementation Highlights

### Design Patterns
The project implements a combination of two design patterns:

#### Factory Method Pattern
Through `IMateriaSource` and `MateriaSource`:
- Defines interface for creating materias
- Encapsulates creation logic in concrete factory
- Allows flexible addition of new materia types
- Centralizes object creation

#### Prototype Pattern
Through `AMateria`'s clone mechanism:
- Each materia can create copies of itself
- Used within factory implementation
- Enables efficient object creation
- Maintains proper type information

These patterns work together:
- Factory Method decides which prototype to use
- Prototype handles the actual object creation
- Combined approach provides both flexibility and efficiency

### Linked List for Floor Management
- Allows unlimited floor capacity
- Efficient memory usage
- Proper cleanup when program exits

### Character Counting
- Tracks the number of character instances
- Identifies the last character for floor cleanup
- Prevents premature floor cleanup

### Memory Management Strategy
- No memory leaks in any test case
- Properly handles ownership transfer
- Manages cleanup in correct order
