/**
 * @file Chapter01_Forces.h
 * @brief Book - Chapter 1: Forces (Weight, Buoyancy, Equilibrium)
 *
 * @image html buoyancy_diagram.png "Buoyant force concept"
 *
 * The buoyant force equals the weight of displaced fluid:
 * \f$ B = \rho \cdot \Delta V \f$
 */


 #pragma once

 namespace Stability::Book::Chapter01 {
 
 /**
  * @brief Compute buoyant force given displaced volume.
  */
 double buoyantForce(double displacedVolume, double waterDensity = 1.025);
 
 /**
  * @brief Check equilibrium difference (positive = floating up, negative = sinking).
  */
 double equilibriumDifference(double weightShip, double displacedVolume, double waterDensity = 1.025);
 
 /**
  * @brief True if weight equals buoyant force within tolerance.
  */
 bool isInEquilibrium(double weightShip, double displacedVolume, double waterDensity = 1.025);
 
 } // namespace Stability::Book::Chapter01
 
