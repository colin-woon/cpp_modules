```
notes.cpp for d06
Created on : Tue Oct 28 14:29:00 2014
Made by : David "Thor" GIRON <thor@42.fr>

Cast               | Conv. | Reint. | Upcast | Downcast | Type qual.
-------------------|-------|--------|--------|----------|-----------
Implicit           | Yes   |        | Yes    |          |
static_cast        | Yes   |        | Yes    | Yes      |
dynamic_cast       |       |        | Yes    | Yes      |
const_cast         |       |        |        |          | Yes
reinterpret_cast   |       | Yes    | Yes    | Yes      |
-------------------|-------|--------|--------|----------|-----------
Legacy C cast      | Yes   | Yes    | Yes    | Yes      | Yes


Cast               | Semantic check | Reliable at run | Tested at run
-------------------|----------------|-----------------|---------------
Implicit           | Yes            | Yes             |
static_cast        | Yes            |                 |
dynamic_cast       | Yes            |                 | Yes
const_cast         |                |                 |
reinterpret_cast   |                |                 |
-------------------|----------------|-----------------|---------------
Legacy C cast      |                |                 |
```
