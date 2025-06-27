//
// Created by xqula on 21.06.24.
//

#include "factorycar.h"
#include "detail/body.h"
#include "detail/engine.h"
#include "detail/transmission.h"
#include "detail/wheel.h"
#include "car/sportcar.h"
#include "car/racingcar.h"

using namespace factory;

/*
 * Creates a new BMW sport car.
 *
 * @return A unique pointer to a new BMW sport car.
 */
auto FactoryCar::createSportCarBMW() -> std::unique_ptr<car::Car> {
    return std::make_unique<car::SportCar>( "BMW",
                                       "AAA",
                                       std::make_unique<detail::Body>( "BMW",
                                                                       "body",
                                                                       "white",
                                                                       detail::TYPE_MATERIAL::METAL),
                                       std::make_unique<detail::Engine>("BMW",
                                                                        "engine",
                                                                        1000,
                                                                        300 ),
                                       std::make_unique<detail::Transmission>("BMW",
                                                                              "transmission",\
                                                                              5,
                                                                              detail::TYPE_OF_TRANSMISSION::AUTOMATIC),
                                       std::make_unique<detail::Wheel>("BMW",
                                                                       "wheel",
                                                                       18,
                                                                       100,
                                                                       detail::SPEED_INDEX::P),
                                       true
                                       );
}

/*
 * Creates a new Audi sport car.
 *
 * @return A unique pointer to a new Audi sport car.
 */
auto FactoryCar::createSportCarAudi() -> std::unique_ptr<car::Car> {
    return std::make_unique<car::SportCar>( "Audi",
                                            "XXX",
                                            std::make_unique<detail::Body>( "BMW",
                                                                                           "body",
                                                                                           "black",
                                                                                           detail::TYPE_MATERIAL::ALUMINUM),
                                           std::make_unique<detail::Engine>("BMW",
                                                                            "engine",
                                                                            1200,
                                                                            310 ),
                                           std::make_unique<detail::Transmission>("BMW",
                                                                                  "transmission",\
                                                                                  8,
                                                                                  detail::TYPE_OF_TRANSMISSION::ROBOT),
                                           std::make_unique<detail::Wheel>("BMW",
                                                                           "wheel",
                                                                           21,
                                                                           120,
                                                                           detail::SPEED_INDEX::Q),
                                           false
                                             );
}

/*
 * Creates a new Ferrari racing car.
 *
 * @return A unique pointer to a new Ferrari racing car.
 */
auto FactoryCar::createRacingCarFerrari() -> std::unique_ptr<car::Car> {
    return std::make_unique<car::RacingCar>( "Ferrari", "YYY", std::make_unique<detail::Body>( "Ferrari",
                                                                                               "body",
                                                                                               "red",
                                                                                               detail::TYPE_MATERIAL::CARBON),
                                             std::make_unique<detail::Engine>("Ferrari",
                                                                              "engine",
                                                                              1200,
                                                                              310 ),
                                             std::make_unique<detail::Transmission>("Ferrari",
                                                                                    "transmission",\
                                                                                    12,
                                                                                    detail::TYPE_OF_TRANSMISSION::MANUAL),
                                             std::make_unique<detail::Wheel>("BMW",
                                                                             "wheel",
                                                                             23,
                                                                             180,
                                                                             detail::SPEED_INDEX::V),
                                             car::TYPE_RACING::F1
                                             );
}

/*
 * Creates a new Mercedes racing car.
 *
 * @return A unique pointer to a new Mercedes racing car.
 */
auto FactoryCar::createRacingCarMercedes() -> std::unique_ptr<car::Car> {
    return std::make_unique<car::RacingCar>( "Mercedes", "ZZZ", std::make_unique<detail::Body>( "Ferrari",
                                                                                                "body",
                                                                                                "red",
                                                                                                detail::TYPE_MATERIAL::CARBON),
                                             std::make_unique<detail::Engine>("Mercedes",
                                                                              "engine",
                                                                              1200,
                                                                              310 ),
                                             std::make_unique<detail::Transmission>("Mercedes",
                                                                                    "transmission",\
                                                                                    8,
                                                                                    detail::TYPE_OF_TRANSMISSION::MANUAL),
                                             std::make_unique<detail::Wheel>("Mercedes",
                                                                             "wheel",
                                                                             18,
                                                                             140,
                                                                             detail::SPEED_INDEX::W),
                                             car::TYPE_RACING::DRIFT
                                             );
}
