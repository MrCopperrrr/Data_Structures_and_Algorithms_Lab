// Insert a Term object directly
void Polynomial::insertTerm(const Term& term) {
    insertTerm(term.coeff, term.exp);
}

// Insert term with coefficient and exponent
void Polynomial::insertTerm(double coeff, int exp) {
    // If the coefficient is zero, there's no need to insert it
    if (coeff == 0.0) return;

    // Create the new term to insert
    Term newTerm(coeff, exp);

    // If the list is empty, insert as the first term
    if (this->terms->empty()) {
        this->terms->add(newTerm);
        return;
    }

    // Iterate through the list and insert the term in the right position
    SLinkedList<Term>::Iterator it = this->terms->begin();
    int pos = 0;  // Position to insert the new term

    // Traverse the linked list to find the correct position
    while (it != this->terms->end()) {
        Term& currentTerm = *it;

        // If we find a term with the same exponent, we add the coefficients
        if (currentTerm.exp == exp) {
            currentTerm.coeff += coeff;

            // If the resulting coefficient is 0, remove the term
            if (currentTerm.coeff == 0.0) {
                this->terms->removeAt(pos);
            }
            return;
        }

        // If the current term's exponent is smaller, insert before it
        if (currentTerm.exp < exp) {
            break;
        }

        // Move to the next node
        ++it;
        pos++;
    }

    // Insert the new term in the correct position
    this->terms->add(pos, newTerm);
}
