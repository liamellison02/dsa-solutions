# Standard Problem Set V1, Problem 4
def prioritize_observations(observed_species, priority_species):
	pmap, priority, rem = {k:v for v,k in enumerate(priority_species)}, [], []
	for s in observed_species:
		if s in pmap:
			priority.append((pmap[s], s))
		else:
			rem.append(s)
	priority.sort(key=lambda x: x[0])
	rem.sort()
	return [s for _,s in priority] + rem