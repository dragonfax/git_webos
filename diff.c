static int diff_suppress_blank_empty;
static int diff_mnemonic_prefix;
struct funcname_pattern_entry {
	int cflags;
};
static struct funcname_pattern_list {
	struct funcname_pattern_list *next;
	struct funcname_pattern_entry e;
static int parse_funcname_pattern(const char *var, const char *ep, const char *value, int cflags)
	struct funcname_pattern_list *pp;
		if (!strncmp(pp->e.name, name, namelen) && !pp->e.name[namelen])
		pp->e.name = xmemdupz(name, namelen);
	free(pp->e.pattern);
	pp->e.pattern = xstrdup(value);
	pp->e.cflags = cflags;
	if (!strcmp(var, "diff.mnemonicprefix")) {
		diff_mnemonic_prefix = git_config_bool(var, value);
		return 0;
	}
	/* like GNU diff's --suppress-blank-empty option  */
	if (!strcmp(var, "diff.suppress-blank-empty")) {
		diff_suppress_blank_empty = git_config_bool(var, value);
		return 0;
	}

				return parse_funcname_pattern(var, ep, value,
					0);
			} else if (!strcmp(ep, ".xfuncname")) {
				if (!value)
					return config_error_nonbool(var);
				return parse_funcname_pattern(var, ep, value,
					REG_EXTENDED);
	const char *a_prefix, *b_prefix;

	if (diff_mnemonic_prefix && DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}
	quote_two_c_style(&a_name, a_prefix, name_a, 0);
	quote_two_c_style(&b_name, b_prefix, name_b, 0);
	xdi_diff_outf(&minus, &plus, fn_out_diff_words_aux, diff_words,
		      &xpp, &xecfg, &ecb);
	int has_trailing_newline, has_trailing_carriage_return;

	has_trailing_newline = (len > 0 && line[len-1] == '\n');
	has_trailing_carriage_return = (len > 0 && line[len-1] == '\r');
	if (has_trailing_carriage_return)
		len--;
	if (has_trailing_carriage_return)
		fputc('\r', file);
	if (diff_suppress_blank_empty
	    && len == 2 && line[0] == ' ' && line[1] == '\n') {
		line[0] = '\n';
		len = 1;
	}

static int dirstat_compare(const void *_a, const void *_b)
{
	const struct dirstat_file *a = _a;
	const struct dirstat_file *b = _b;
	return strcmp(a->name, b->name);
}

	dir.cumulative = DIFF_OPT_TST(options, DIRSTAT_CUMULATIVE);
		 * made to the preimage. In --dirstat-by-file mode, count
		 * damaged files, not damaged lines. This is done by
		 * counting only a single damaged line per file.
		if (DIFF_OPT_TST(options, DIRSTAT_BY_FILE) && damage > 0)
			damage = 1;
	qsort(dir.files, dir.nr, sizeof(dir.files[0]), dirstat_compare);
static const struct funcname_pattern_entry *funcname_pattern(const char *ident)
	struct funcname_pattern_list *pp;
		if (!strcmp(ident, pp->e.name))
			return &pp->e;
static const struct funcname_pattern_entry builtin_funcname_pattern[] = {
	{ "bibtex", "(@[a-zA-Z]{1,}[ \t]*\\{{0,1}[ \t]*[^ \t\"@',\\#}{~%]*).*$",
	  REG_EXTENDED },
	{ "html", "^[ \t]*(<[Hh][1-6][ \t].*>.*)$", REG_EXTENDED },
	{ "java",
	  "!^[ \t]*(catch|do|for|if|instanceof|new|return|switch|throw|while)\n"
	  "^[ \t]*(([ \t]*[A-Za-z_][A-Za-z_0-9]*){2,}[ \t]*\\([^;]*)$",
	  REG_EXTENDED },
	{ "pascal",
	  "^((procedure|function|constructor|destructor|interface|"
		"implementation|initialization|finalization)[ \t]*.*)$"
	  "\n"
	  "^(.*=[ \t]*(class|record).*)$",
	  REG_EXTENDED },
	{ "php", "^[\t ]*((function|class).*)", REG_EXTENDED },
	{ "python", "^[ \t]*((class|def)[ \t].*)$", REG_EXTENDED },
	{ "ruby", "^[ \t]*((class|module|def)[ \t].*)$",
	  REG_EXTENDED },
	{ "bibtex", "(@[a-zA-Z]{1,}[ \t]*\\{{0,1}[ \t]*[^ \t\"@',\\#}{~%]*).*$",
	  REG_EXTENDED },
	{ "tex",
	  "^(\\\\((sub)*section|chapter|part)\\*{0,1}\\{.*)$",
	  REG_EXTENDED },
static const struct funcname_pattern_entry *diff_funcname_pattern(struct diff_filespec *one)
	const char *ident;
	const struct funcname_pattern_entry *pe;
	pe = funcname_pattern(ident);
	if (pe)
		return pe;
			return &builtin_funcname_pattern[i];
void diff_set_mnemonic_prefix(struct diff_options *options, const char *a, const char *b)
{
	if (!options->a_prefix)
		options->a_prefix = a;
	if (!options->b_prefix)
		options->b_prefix = b;
}

	const char *a_prefix, *b_prefix;

	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}
	a_one = quote_two(a_prefix, name_a + (*name_a == '/'));
	b_two = quote_two(b_prefix, name_b + (*name_b == '/'));
		const struct funcname_pattern_entry *pe;
		pe = diff_funcname_pattern(one);
		if (!pe)
			pe = diff_funcname_pattern(two);
		if (pe)
			xdiff_set_find_func(&xecfg, pe->pattern, pe->cflags);
		xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
			      &xpp, &xecfg, &ecb);
		xdi_diff_outf(&mf1, &mf2, diffstat_consume, diffstat,
			      &xpp, &xecfg, &ecb);
		xecfg.ctxlen = 1; /* at least one context line */
		xdi_diff_outf(&mf1, &mf2, checkdiff_consume, &data,
			      &xpp, &xecfg, &ecb);
	DIFF_OPT_CLR(options, DIRSTAT_CUMULATIVE);
	if (!diff_mnemonic_prefix) {
		options->a_prefix = "a/";
		options->b_prefix = "b/";
	}
	else if (!strcmp(arg, "--cumulative")) {
		options->output_format |= DIFF_FORMAT_DIRSTAT;
		DIFF_OPT_SET(options, DIRSTAT_CUMULATIVE);
	} else if (opt_arg(arg, 0, "dirstat-by-file",
			   &options->dirstat_percent)) {
		options->output_format |= DIFF_FORMAT_DIRSTAT;
		DIFF_OPT_SET(options, DIRSTAT_BY_FILE);
	}
		xdi_diff_outf(&mf1, &mf2, patch_id_consume, &data,
			      &xpp, &xecfg, &ecb);
	if (options->skip_stat_unmatch)