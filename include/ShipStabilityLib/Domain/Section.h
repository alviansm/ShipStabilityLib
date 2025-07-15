/**
 * @file Section.h
 * @brief Defines the Section struct for hydrostatic sectional data.
 */

 #pragma once

 namespace Stability {
 
 /**
  * @brief Represents a single hydrostatic data point.
  *
  * Typically stores data for a given draft:
  * - Waterplane area
  * - First moment of area (KB)
  * - etc.
  */
 struct Section {
     double draft;    ///< Draft at this section (m)
     double area;     ///< Waterplane area (m^2)
     double moment;   ///< First moment of area about baseline (m^3)
 
     Section() : draft(0.0), area(0.0), moment(0.0) {}
     Section(double d, double a, double m) : draft(d), area(a), moment(m) {}
 };
 
 } // namespace Stability
 