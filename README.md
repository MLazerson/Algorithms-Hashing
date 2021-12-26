# 335-project-3
# Clustering a sensor network

Group Members: Malka Lazerson mlazerson@csu.fullerton.edu

*Abstract:*

In this project you will design and implement one algorithm related to hash tables that can aid various distributed algorithms to group sensors. Your project is about reading a fairly small number of distinct Network Interface Controllers (NICs), each being a 6-digit number in hexadecimal) and deciding which digit among the six gives the best balanced distribution of the NICs. You will implement it using C++, compile, test it, and submit the files. No algorithm analysis is needed for this project and no PDF report is to be submitted. The next step is to do research on the Internet about the usefulness of having a .gitignore file and create the file .gitignore in your directory. Then upload everything on GitHub.

*The Hypothesis:*

Different hash functions produce hash chains of various lengths when applied to the same dataset.
Hash tables offer a relatively fast way of storing and retrieving data.

*The Problem:*

Communication is paramount on sensor networks and it relies on grouping sensors into clusters, and providing code to be executed distributively at the sensors to maximize coverage and extend lifetime of the network, thus minimizing energy consumption for transmission. There are several types of sensors used to collect data from the environment; a simpiified classification is available at https://www.variohm.com/news-media/technical-blog-archive/types-of-sensors. A much detailed list is available here https://www.thomasnet.com/articles/instruments-controls/sensors/. 

We are given a sensor network with a fairly small number of MAC addresses, one for each sensor, and we would like to group the sensors to form several clusters of sensors based on their MAC address. A MAC address (Media Access Control address) is a unique identifier assigned to a network interface controller (NIC) for on a network. A MAC Address is often referred to as a hardware address. The MAC addresses are unique and they are used for communication between components or computers. MAC addresses take the form of alphanumeric numbers in hexadecimal format arranged in groups of 2 (usually) separated by a colon. Renaming MAC addresses to minimize bits used for communication (https://dl.acm.org/doi/abs/10.1145/501449.501463 ) is one technique used to work around MAC addresses that are unique and drawn from an extremely large number of possible values.

For example, in Fig.1 00::26:C7:CF:94:98 is the MAC address for a component called Wireless-N 1000 which is a wireless adapter (https://ark.intel.com/content/www/us/en/ark/products/59480/intel-centrino-wireless-n-1000-single-band.html). 

Fig.1 MAC-adreso - Vikipedio, Creator: Raimond Spekking, from https://eo.wikipedia.org/wiki/MAC-adreso  This file is licensed under the Creative Commons Attribution-Share Alike 3.0 Unported license.

For our problem we consider a MAC address on 48 bits, or 6 hexadecimals, called MAC-48 and which it now refers to as EUI-48 identifiers (https://en.wikipedia.org/wiki/MAC_address).

The first 6-digits (say 00:26:C7 or 0026C7) of the MAC Address identifies the manufacturer, called as Organizational Unique Identifier (OUI); for the complement in Fig. 1 it would be Intel. The next 6 digits of the MAC address are Network Interface Controller (NIC) specific and are unique to each product (https://www.geeksforgeeks.org/introduction-of-mac-address-in-computer-network/).

For our problem, the following scenario motivates solving it. We are given a sensor network with a large number of MAC addresses, one for each sensor, and we would like to group the sensors to form a cluster of sensors based on their MAC address. We assume that the sensors are from the same manufacturer, so we consider only the NIC numbers are of importance for this problem. We assume that the MAC addresses are 6-digit numbers instead of 6-alphanumeric characters from the set {0..9, A..F}.

The first hash table organizes NICs based on the first digit, the second hash table has the hash function that organizes the NICs based on the second digit, etc. tha last hash table has the hash function that organizes the NICs based on the sixth (the last) digit.
