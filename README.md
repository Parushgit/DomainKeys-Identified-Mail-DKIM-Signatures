# DomainKeys-Identified-Mail-DKIM-Signatures

Write a simple C code using Fork – Exec system calls to apply the core DKIM algorithms
on the email repository collected above. The steps are as follows:

-> Generate the public – private RSA key pairs for both 1024 and 2048 bits using openssl
command. Store them as rsaprivatekey1024.pem & rsapublickey1024.pem and
rsaprivatekey2048.pem & rsapublickey2048.pem.

-> Apply both SHA digests SHA1 and SHA256 and sign the messages using the RSA
private keys generated above (applying the SHA digest and signing can be achieved by
using a single openssl command, i.e., SHA1/SHA256 + 1024/2048 RSA Signing).
Algorithm Output folder (store the cipher generated
here as cipher.1 … cipher.10)
SHA1 + rsaprivatekey1024 signing Output/1024SHA1
SHA256 + rsaprivatekey1024 signing Output/1024SHA256
SHA1 + rsaprivatekey2048 signing Output/2048SHA1
SHA256 + rsaprivatekey2048 signing Output/2048SHA256

-> Calculate the time taken in milliseconds for applying each of the above algorithms for
5 test runs (i.e., sign 5 times the same message and average the times) using any
standard C programming time libraries. Plot a graph depicting the same for each of
them using the test run data.
Note: You will be graded based solely on how readable your graphs are.

-> As a next step verify the RSA signature using the rsapublickey1024 and
rsapublickey2048 public keys generated above and taking the ciphers from the output
folders above along with the original email messages as input for verification.

-> Calculate the time in milliseconds for verification of each of the algorithms in the table
above for the 5 test runs (i.e., verify 5 times the same ciphertext and average the times)
using any standard C programming time libraries. Plot a graph depicting the same for
each of them using the test run data.
