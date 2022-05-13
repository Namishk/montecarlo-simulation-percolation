# Monte Carlo simulation to estimate percolation threshold.	

## Percoaltion
Given a composite systems comprised of randomly distributed insulating and metallic materials: what fraction of the materials need to be metallic so that the composite system is an electrical conductor? Given a porous landscape with water on the surface (or oil below), under what conditions will the water be able to drain through to the bottom (or the oil to gush through to the surface)? Scientists have defined an abstract process known as percolation to model such situations.
<br>

## Modelling
To model this system we use N x N grid of sites each site either open or close. We connect open sites to form a chain and if top and botton rows are connected then we can say that the system peprcolates.


![alt text](percolation%20example.png)

## Problem
The probability of each site being open is p and being close is (1 - p), we use bernoulli distribution to open sites. And for each p we check if the system percolates.

## Then after plotting the graph vacency probability vs percolation probability we can find the percolation threshold.

> ## Plots for different N

>  ![alt text](Montecarlo%20Simulation%2010%20x%2010.png)
>  ``` Plot for N = 10```

> ![alt text](Montecarlo%20Simulation%20100%20x%20100.png)
>  ```Plot for N = 100```

> ![alt text](Montecarlo%20Simulation%20200%20x%20200.png)
>  ```Plot for N = 200```
