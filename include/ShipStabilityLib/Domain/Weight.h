/**
 * @file Weight.h
 * @brief Defines the Weight struct for individual weights onboard.
 */

 #pragma once

 #include <string>
 
 namespace Stability {
 
 /**
  * @brief Represents a single weight element on a vessel.
  *
  * This could be cargo, ballast, stores, or any individual mass with a defined
  * center of gravity. It is used to compute the overall KG and mass distribution.
  */
 struct Weight {
     std::string name;   ///< Descriptive name (e.g., "Cargo Hold #1")
     double mass;        ///< Weight mass in metric tons
     double x;           ///< Longitudinal center of gravity (m from AP)
     double y;           ///< Transverse center of gravity (m from centerline)
     double z;           ///< Vertical center of gravity (m above baseline)
 
     /**
      * @brief Default constructor initializing values to zero.
      */
     Weight() : name(""), mass(0.0), x(0.0), y(0.0), z(0.0) {}
 
     /**
      * @brief Parameterized constructor.
      * @param n Name of the weight.
      * @param m Mass in tons.
      * @param lx Longitudinal CoG (m).
      * @param ty Transverse CoG (m).
      * @param vz Vertical CoG (m).
      */
     Weight(const std::string& n, double m, double lx, double ty, double vz)
         : name(n), mass(m), x(lx), y(ty), z(vz) {}
 };
 
 } // namespace Stability
 