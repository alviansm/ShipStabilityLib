/**
 * @file Vessel.h
 * @brief Defines the Vessel struct containing main particulars and hydrostatic data.
 */

 #pragma once

 #include <string>
 #include <vector>
 #include "ShipStabilityLib/Domain/Weight.h"
 
 namespace Stability {
 
 /**
  * @brief Represents a single sectional hydrostatic data point.
  *
  * This can be used for interpolating hydrostatic properties (area, moment, etc.)
  * at a given draft.
  */
 struct Section {
     double draft;    ///< Draft at this section (m)
     double area;     ///< Waterplane area (m^2)
     double moment;   ///< First moment of area about baseline (m^3)
 };
 
 /**
  * @brief Represents a vessel's main particulars and associated data.
  *
  * It contains:
  * - Principal dimensions (LBP, beam, depth)
  * - Hydrostatic data (sectional curves)
  * - List of weights onboard
  */
 struct Vessel {
     // Basic info
     std::string name;  ///< Vessel name
 
     // Principal dimensions
     double LBP;        ///< Length between perpendiculars (m)
     double beam;       ///< Breadth (m)
     double depth;      ///< Depth to main deck (m)
 
     // Hydrostatic sectional data
     std::vector<Section> hydrostaticTable; ///< Predefined hydrostatic data for drafts
 
     // Weights
     std::vector<Weight> weights; ///< List of onboard weights
 
     /**
      * @brief Default constructor initializing dimensions to zero.
      */
     Vessel() : name(""), LBP(0.0), beam(0.0), depth(0.0) {}
 
     /**
      * @brief Adds a weight entry to the vessel.
      * @param w The Weight to add.
      */
     void addWeight(const Weight& w) {
         weights.push_back(w);
     }
 
     /**
      * @brief Computes the total displacement (sum of all weights).
      * @return Total mass in tons.
      */
     double totalDisplacement() const {
         double total = 0.0;
         for (const auto& w : weights) {
             total += w.mass;
         }
         return total;
     }
 
     /**
      * @brief Computes the vertical center of gravity KG.
      * @return KG in meters above baseline.
      */
     double KG() const {
         double totalMass = totalDisplacement();
         if (totalMass <= 1e-9) return 0.0;
 
         double moment = 0.0;
         for (const auto& w : weights) {
             moment += w.mass * w.z;
         }
         return moment / totalMass;
     }
 };
 
 } // namespace Stability
 