/**
 * @file VesselJsonParser.h
 * @brief JSON parser for loading/saving vessel data.
 */

 #pragma once

 #include <string>
 #include "ShipStabilityLib/Domain/Vessel.h"
 
 namespace Stability {
 
 /**
  * @brief Loads and saves Vessel data in JSON format.
  */
 class VesselJsonParser {
 public:
     /**
      * @brief Load a vessel from a JSON file.
      * @param path File path to JSON.
      * @return Parsed Vessel object.
      */
     static Vessel fromFile(const std::string& path);
 
     /**
      * @brief Save a vessel to a JSON file.
      * @param vessel Vessel to save.
      * @param path Destination path.
      */
     static void toFile(const Vessel& vessel, const std::string& path);
 };
 
 } // namespace Stability
 