# Optimization Engine [![Tweet](https://img.shields.io/twitter/url/http/shields.io.svg?style=social)](https://twitter.com/intent/tweet?text=Fast%20and%20accurate%20nonconvex%20optimization&url=https://alphaville.github.io/optimization-engine/&via=isToxic&hashtags=optimization,rustlang,matlab,python)

[![Build Status](https://travis-ci.org/alphaville/optimization-engine.svg?branch=master)](https://travis-ci.org/alphaville/optimization-engine) [![Build status](https://ci.appveyor.com/api/projects/status/fy9tr4xmqq3ka4aj/branch/master?svg=true)](https://ci.appveyor.com/project/alphaville/optimization-engine/branch/master)

[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/) [![Apache v2 license](https://img.shields.io/badge/License-Apache%20v2-blue.svg)](https://github.com/alphaville/optimization-engine/blob/master/LICENSE-APACHE) [![Gitter](https://badges.gitter.im/alphaville/optimization-engine.svg)](https://gitter.im/alphaville/optimization-engine?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge) [![Chat on Discord](https://img.shields.io/badge/chat-on%20discord-gold.svg)](https://discord.gg/mfYpn4V) [![Chat on IRC](https://img.shields.io/badge/chat-on%20irc-pink.svg)](https://webchat.freenode.net/?channels=%23optimization_engine)

![OpEn logo](https://pbs.twimg.com/media/D1d8iOuXQAUFKJT.png:large)


Optimization Engine (OpEn) is a solver for embedded nonconvex optimization.

**Documentation available at** [**alphaville.github.io/optimization-engine**](https://alphaville.github.io/optimization-engine/)

## Features

**OpEn** is the counterpart of **CVXGen** for nonconvex problems.

- Fast nonconvex parametric optimization
- Numerical algorithm written in Rust
- Provably safe memory management
- Ideal for nonlinear MPC applications (e.g., autonomous navigation)


## Demos

### Code generation

Code generation? Piece of cake!

**OpEn** generates parametric optimizer modules in Rust - it's blazingly fast - it's safe - it can run on embedded devices.

You can use the [MATLAB](https://alphaville.github.io/optimization-engine/docs/matlab-interface) or [Python interface](https://alphaville.github.io/optimization-engine/docs/python-interface) of OpEn to generate Rust code for your parametric optimizer.

This can then be called directly, using Rust, or, it can be consumed as a service over a [UDP socket](https://alphaville.github.io/optimization-engine/docs/udp-sockets).

![Code generation](website/static/img/115ba54c2ad0.gif "Easy Code Generation")

You can generate a parametric optimizer in just very few lines of code and in no time.

OpEn allows application developers and researchers to focus on the challenges of the application, rather than the tedious task of solving the associated parametric optimization problems (as in nonlinear model predictive control).

### Embedded applications
OpEn can run on embedded devices; here we see it running on an intel Atom for the autonomous navigation of a lab-scale micro aerial vehicle - the controller runs at **20Hz** using only **15%** CPU!

![Autonomous Aerial Vehicle](website/static/img/e8f236af8d38.gif "Fast NMPC of MAV")


## Getting started

- [More information about OpEn](https://alphaville.github.io/optimization-engine/docs/open-intro)
- [Quick installation guide](https://alphaville.github.io/optimization-engine/docs/installation)
- [OpEn in Rust](https://alphaville.github.io/optimization-engine/docs/openrust)
- [OpEn in MATLAB](https://alphaville.github.io/optimization-engine/docs/matlab-interface)
- [OpEn in Python](https://alphaville.github.io/optimization-engine/docs/python-interface)
- [UDP communication protocol](https://alphaville.github.io/optimization-engine/docs/udp-sockets)
- [Example: autonomous vehicle](https://alphaville.github.io/optimization-engine/docs/example-nav)
- [Frequently asked questions](https://alphaville.github.io/optimization-engine/docs/faq)

## Contact us

- Join us on [Discord](https://discord.gg/mfYpn4V)
- Reach us on [Gitter](https://gitter.im/alphaville/optimization-engine)



## License

OpEn is a free open source project. You can use it under the terms of either [Apache license v2.0](LICENSE-APACHE) or [MIT license](LICENSE-MIT).


## Authors
- [Pantelis Sopasakis](https://alphaville.github.io)
- [Emil Fresk](https://github.com/korken89)

## Contributions

Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, as defined in the Apache-2.0 license, shall be dual licensed as above, without any additional terms or conditions.

A list of contributors is automatically generated by github [here](https://github.com/alphaville/optimization-engine/graphs/contributors).
